//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);

//cording here
let [f1,f2,f3] =input;

let set1 = f2*2 + f3*4;
let set2 = f1*2 + f3*2;
let set3 = f2*2 + f1*4;

console.log(Math.min(set1,set2,set3));