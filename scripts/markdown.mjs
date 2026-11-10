import {execFileSync} from 'node:child_process';
import {existsSync, readFileSync} from 'node:fs';
import GitHubSlugger from 'github-slugger';
import {toString} from 'mdast-util-to-string';
import {parseFragment} from 'parse5';
import remarkGfm from 'remark-gfm';
import remarkParse from 'remark-parse';
import {unified} from 'unified';

const parser = unified().use(remarkParse).use(remarkGfm);

export function repositoryFiles() {
  // Keep spelling and case as Git sees them, including paths containing spaces or Korean.
  const names = execFileSync('git', ['ls-files', '-z', '--cached', '--others', '--exclude-standard'], {encoding: 'utf8'});
  return new Set(names.split('\0').filter(name => name && existsSync(name)));
}

export function isArticle(file) {
  return /^(?:cs|languages|projects|software-engineering)\/[^/]+\/(?:theory\/|notes\/[^/]+\/note\/).+\.md$/i.test(file)
    && !/(?:^|\/)readme\.md$/i.test(file);
}

export function readMarkdown(file) {
  return parseMarkdown(readFileSync(file, 'utf8'));
}

function walk(node, visit, line = 1) {
  const start = node.position?.start.line ?? line;
  visit(node, start);
  for (const child of node.children ?? []) walk(child, visit, start);
}

export function parseMarkdown(markdown) {
  // Keep line numbers when hiding YAML from the CommonMark parser.
  const source = markdown.replace(/^---\r?\n[\s\S]*?\r?\n---[ \t]*(?=\r?\n|$)/,
    block => block.replace(/[^\n]/g, ' '));
  const tree = parser.parse(source);
  const slugger = new GitHubSlugger();
  const headings = [], anchors = new Set(), links = [], definitions = new Map(), references = [];
  walk(tree, (node, line) => {
    if (node.type === 'heading') {
      const title = toString(node);
      const id = slugger.slug(title);
      headings.push({title, id, depth: node.depth, line});
      anchors.add(id);
    } else if (node.type === 'link' || node.type === 'image') {
      links.push({url: node.url, line});
    } else if (node.type === 'definition') {
      if (!definitions.has(node.identifier)) definitions.set(node.identifier, node.url);
    } else if (node.type === 'linkReference' || node.type === 'imageReference') {
      references.push({id: node.identifier, line});
    } else if (node.type === 'html') {
      const raw = parseFragment(node.value, {sourceCodeLocationInfo: true});
      function collect(element) {
        for (const {name, value} of element.attrs ?? []) {
          if (name === 'id' || (element.tagName === 'a' && name === 'name')) anchors.add(value);
          if (name === 'href' || name === 'src') links.push({url: value, line: line + (element.sourceCodeLocation?.startLine ?? 1) - 1});
        }
        for (const child of element.childNodes ?? []) collect(child);
      }
      collect(raw);
    }
  });
  for (const ref of references) {
    if (definitions.has(ref.id)) links.push({url: definitions.get(ref.id), line: ref.line});
  }
  const titleHeading = tree.children.find(node => node.type === 'heading' && node.depth <= 2);
  const comments = tree.children
    .filter(node => node.type === 'html' && /^<!--[^\n]*-->$/.test(node.value.trim()))
    .map(node => ({text: node.value.trim(), line: node.position.start.line}));
  return {title: titleHeading ? toString(titleHeading).trim() : '', headings, anchors, links, comments};
}
