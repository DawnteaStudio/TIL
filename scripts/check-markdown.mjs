import path from 'node:path/posix';
import {pathToFileURL} from 'node:url';
import {isArticle, readMarkdown, repositoryFiles} from './markdown.mjs';

function destination(source, link) {
  let pathname, hash, absolute = false;
  if (/^(?:[a-z][a-z\d+.-]*:|\/\/)/i.test(link)) {
    const url = new URL(link, 'https://github.com');
    const match = url.pathname.match(/^\/DawnteaStudio\/TIL\/(?:blob|tree|raw)\/main(?:\/(.*))?$/i);
    if (url.hostname !== 'github.com' || !match) return null;
    pathname = match[1] ?? '';
    hash = url.hash.slice(1);
    absolute = true;
  } else {
    const index = link.indexOf('#');
    pathname = (index < 0 ? link : link.slice(0, index)).split('?')[0];
    hash = index < 0 ? '' : link.slice(index + 1);
    absolute = pathname.startsWith('/');
  }
  const decoded = decodeURIComponent(pathname);
  const file = absolute ? path.normalize(decoded.replace(/^\/+/, '') || '.') :
    decoded ? path.join(path.dirname(source), decoded) : source;
  return {file: file.replace(/\/$/, '') || '.', hash: decodeURIComponent(hash)};
}

export function checkMarkdown(files, documents) {
  const errors = [], directories = new Set(['.']), edges = new Map();
  for (const file of files) {
    for (let dir = path.dirname(file); dir !== '.'; dir = path.dirname(dir)) directories.add(dir);
  }
  for (const [source, doc] of documents) {
    const outgoing = new Set();
    edges.set(source, outgoing);
    for (const {url, line} of doc.links) {
      const where = source + ':' + line;
      if (!url) { errors.push(where + ' 빈 링크'); continue; }
      let dest;
      try { dest = destination(source, url); }
      catch { errors.push(where + ' 잘못된 URL: ' + url); continue; }
      if (!dest) continue;
      let {file, hash} = dest;
      if (directories.has(file)) {
        const readme = path.join(file, 'README.md');
        if (!files.has(readme)) continue; // The directory itself is a valid GitHub target.
        file = readme;
      } else if (!files.has(file)) {
        errors.push(where + ' 없는 경로: ' + file);
        continue;
      }
      const target = documents.get(file);
      if (hash && target && !target.anchors.has(hash) && !target.anchors.has(hash.replace(/^user-content-/, ''))
          && !/^(?:L\d+(?:-L\d+)?|top|readme)$/i.test(hash)) {
        errors.push(where + ' 없는 제목: ' + file + '#' + hash);
        continue;
      }
      outgoing.add(file);
    }
  }
  const reachable = new Set(['README.md']);
  for (const file of reachable) for (const next of edges.get(file) ?? []) reachable.add(next);
  const articles = [...documents.keys()].filter(isArticle);
  // Cross-links between articles (or from an example in templates/) must not mask a broken parent index.
  for (const article of articles) {
    const [area, topic, section, source] = article.split('/');
    const chain = ['README.md', area + '/README.md', area + '/' + topic + '/README.md'];
    if (section === 'notes') chain.push([area, topic, 'notes', source, 'README.md'].join('/'));
    chain.push(article);
    for (let i = 1; i < chain.length; i++) {
      if (!edges.get(chain[i - 1])?.has(chain[i])) {
        const message = chain[i - 1] + ' 목차에 직접 연결되지 않음: ' + chain[i];
        if (!errors.includes(message)) errors.push(message);
      }
    }
  }
  const cards = [...documents.keys()].filter(file => /^coding-test\/code_tree\/\d{6}\/[^/]+\/README\.md$/.test(file));
  const codeDir = /^coding-test\/code_tree\/\d{6}\/[^/]+\//;
  const solutions = [...files].filter(file => codeDir.test(file) && /\.(?:c|cc|cpp|cxx|py|java|js|ts|kt|rs|go|swift|rb|cs)$/i.test(file));
  for (const file of [...articles, ...cards, ...solutions]) {
    if (!reachable.has(file)) errors.push('루트 README에서 도달할 수 없음: ' + file);
  }
  const coverage = group => group.filter(f => reachable.has(f)).length + '/' + group.length;
  return {errors, summary: 'Markdown ' + documents.size + '개 · 루트에서 학습 글 ' + coverage(articles)
    + ' · CodeTree 문제 ' + coverage(cards) + ' · CodeTree 풀이 코드 ' + coverage(solutions)};
}

if (process.argv[1] && import.meta.url === pathToFileURL(process.argv[1]).href) {
  const files = repositoryFiles();
  const docs = new Map([...files].filter(f => /\.md$/i.test(f)).map(f => [f, readMarkdown(f)]));
  const {summary, errors} = checkMarkdown(files, docs);
  console.log(summary);
  for (const message of errors) console.error(message);
  if (errors.length) process.exitCode = 1;
}
