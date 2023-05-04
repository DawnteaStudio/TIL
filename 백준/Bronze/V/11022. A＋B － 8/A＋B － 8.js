//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [tests, ...test] = input;
let str = '';

for(i = 1; i <= tests; i++){
  let[head, tail] = input[i].split(' ').map(Number);
  str += `Case #${i}: ${head} + ${tail} = ${head+tail}` + '\n';
}

console.log(str.trim());