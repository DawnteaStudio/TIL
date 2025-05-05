//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n').map(BigInt);

//cording here
let [apples, diff] = input;
let lessApple = (apples-diff)/2n;
let moreApple = lessApple+diff;

console.log(moreApple.toString());
console.log(lessApple.toString());