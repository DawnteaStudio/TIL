//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
const input = require('fs').readFileSync(filePath).toString().trim().split('\n').map(Number);

//cording here
let [head, tail] = input;
console.log(head* (tail%10));
console.log(head* Math.floor(tail%100/10));
console.log(head* Math.floor(tail/100));
console.log(head*tail);