//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [now, time] = input;

let [h,m,s] = now.split(' ').map(Number);
let sOver = 0;
let mOver = 0;

sOver = Math.floor((+time+s)/60);
s = (+time+s)%60;

mOver = Math.floor((m+sOver)/60);
m = (m+sOver)%60;

h = (h + mOver)%24;

console.log(h,m,s);