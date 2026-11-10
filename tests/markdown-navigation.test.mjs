import {test} from 'node:test';
import assert from 'node:assert/strict';
import {parseMarkdown} from '../scripts/markdown.mjs';
import {checkMarkdown} from '../scripts/check-markdown.mjs';
import {updateArticle} from '../scripts/article-toc.mjs';

test('an example cross-link cannot conceal a missing language in the root navigation', () => {
  const files = new Map([
    ['README.md', '[Languages](languages/) · [example](languages/java/theory/A%20B.md)'],
    ['languages/README.md', '# Languages'],
    ['languages/java/README.md', '[theory](theory/A%20B.md)'],
    ['languages/java/theory/A B.md', '# Java'],
  ]);
  const check = () => checkMarkdown(new Set(files.keys()), new Map([...files].map(([file, md]) => [file, parseMarkdown(md)])));
  assert.deepEqual(check().errors, ['languages/README.md 목차에 직접 연결되지 않음: languages/java/README.md']);
  files.set('languages/README.md', '[Java](java/)');
  assert.deepEqual(check().errors, []);
  files.set('languages/java/README.md', '[theory](theory/A%20B.md#typo)');
  assert.ok(check().errors.some(error => error.includes('없는 제목')));
});

test('editable prose and code examples survive TOC generation, with unique duplicate heading anchors', () => {
  const md = '# Main\n\n```md\n<!-- til:toc:start -->\n# demo\n<!-- til:toc:end -->\n```\n\n## 목차\n\n<!-- til:toc:start -->\n<!-- til:toc:end -->\n\n## Example\n\nKeep my notes.\n\n## Example\n';
  const revised = updateArticle(md);
  assert.match(revised, /\(#example-1\)/);
  assert.ok(revised.includes('```md\n<!-- til:toc:start -->\n# demo\n<!-- til:toc:end -->\n```'));
  assert.ok(revised.includes('Keep my notes.'));
  assert.equal(updateArticle(revised), revised);
  assert.throws(() => updateArticle(md.replace('<!-- til:toc:end -->\n\n## Example', '\n## Example')), /마커/);
});
