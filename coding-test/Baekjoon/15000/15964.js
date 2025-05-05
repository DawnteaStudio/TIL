//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split(' ');

function calc(a,b){
  a = parseInt(a);
  b = parseInt(b);
  return (a+b)*(a-b);
}

console.log(calc(input[0], input[1]));