//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split(' ');

// cording here!!
let a = +input[0];
let b = +input[1];
let c = +input[2];

console.log(a+b+c);

