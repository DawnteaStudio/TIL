//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split(' ');

//cording here!!
var a = parseInt(input[0]);
var b = parseInt(input[1]);
console.log(a/b);