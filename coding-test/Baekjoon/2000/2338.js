//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split('\n');

//cording here
let [a,b] = input.map(BigInt);
let str = '';

str += (a+b) + '\n';
str += a-b + '\n';
str += a*b;
console.log(str);
