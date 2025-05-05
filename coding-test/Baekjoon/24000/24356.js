//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here
let [t1, m1, t2, m2] = input;
let start = t1*60+m1;
let end = t2*60+m2;
let time = start > end ? end+(60*24-start) : end-start;
console.log(time, Math.floor(time/30));