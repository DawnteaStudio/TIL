import {readFileSync, writeFileSync} from 'node:fs';
import path from 'node:path/posix';
import {pathToFileURL} from 'node:url';
import {isArticle, parseMarkdown, repositoryFiles} from './markdown.mjs';

const toc = 'toc', chapters = 'chapters';
const order = new Intl.Collator('ko', {numeric: true, sensitivity: 'base'});
const escapeLabel = title => title.replace(/[\\[\]]/g, '\\$&');

function replaceBlock(text, name, build) {
  const start = '<!-- til:' + name + ':start -->', end = '<!-- til:' + name + ':end -->';
  const lines = text.split('\n');
  const {comments} = parseMarkdown(text);
  const locate = marker => comments.filter(c => c.text === marker).map(c => c.line - 1);
  const starts = locate(start), ends = locate(end);
  if (!starts.length && !ends.length) return text;
  if (starts.length !== 1 || ends.length !== 1 || starts[0] >= ends[0]) {
    throw Error(name + ': 자동 구역 마커의 순서 또는 개수를 확인하세요.');
  }
  const separator = text.includes('\r\n') ? '\r\n' : '\n';
  const content = build(starts[0], ends[0]).join(separator);
  return [...lines.slice(0, starts[0] + 1), content, ...lines.slice(ends[0])].join('\n');
}

export function updateArticle(source, {previous, next} = {}) {
  const result = replaceBlock(source, toc, (_start, end) => {
    const headings = parseMarkdown(source).headings.filter(h => h.line > end + 1 && (h.depth === 2 || h.depth === 3));
    const main = headings.filter(h => h.depth === 2);
    const visible = headings.length > 18 && main.length > 1 ? main : headings;
    // GitHub slugs already exclude Markdown delimiters; keep Korean legible in the source.
    return visible.map(h => (h.depth === 3 && main.length ? '  ' : '') + '- [' + escapeLabel(h.title) + '](#' + h.id.replace(/\s/gu, encodeURIComponent) + ')');
  });
  return replaceBlock(result, chapters, () => {
    const item = (direction, chapter) => direction + ': [' + escapeLabel(chapter.title) + '](./' + encodeURIComponent(path.basename(chapter.file)) + ')';
    const items = [];
    if (previous) items.push(item('이전 글', previous));
    items.push('[자료 목차](../README.md)');
    if (next) items.push(item('다음 글', next));
    return [items.join(' · ')];
  });
}

export function reconcileArticles(files, write) {
  const articles = [...files].filter(isArticle).map(file => {
    const text = readFileSync(file, 'utf8');
    return {file, text, title: parseMarkdown(text).title || path.basename(file, '.md')};
  });
  const series = new Map();
  for (const article of articles.filter(a => a.file.includes('/note/'))) {
    const folder = path.dirname(article.file);
    if (!series.has(folder)) series.set(folder, []);
    series.get(folder).push(article);
  }
  for (const list of series.values()) list.sort((a, b) => order.compare(a.file, b.file));
  const changes = [];
  for (const article of articles) {
    const siblings = series.get(path.dirname(article.file)) ?? [];
    const i = siblings.indexOf(article);
    let revised;
    try { revised = updateArticle(article.text, {previous: siblings[i - 1], next: siblings[i + 1]}); }
    catch (error) { throw Error(article.file + ' — ' + error.message); }
    if (article.text !== revised) changes.push([article.file, revised]);
  }
  if (write) for (const [file, text] of changes) writeFileSync(file, text);
  return changes.map(([file]) => file);
}

if (process.argv[1] && import.meta.url === pathToFileURL(process.argv[1]).href) {
  const write = process.argv.includes('--write');
  const changed = reconcileArticles(repositoryFiles(), write);
  if (changed.length) console.log(changed.join('\n'));
  console.log('글 목차·장 이동: ' + changed.length + '개 ' + (write ? '갱신' : '차이'));
  if (changed.length && !write) process.exitCode = 1;
}
