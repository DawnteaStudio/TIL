//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);

//cording here
let [w1, h1, w2, h2] = input;
let width = w1 > w2 ? w1 : w2;
console.log(width*2 + (h1 + h2)*2 + 4 );