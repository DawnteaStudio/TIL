//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split(' ');

//cording here
let a = BigInt(input[0]);
let b = BigInt(input[1]);
let str = '';

str += (a/b) + '\n';
str += a%b;
console.log(str);