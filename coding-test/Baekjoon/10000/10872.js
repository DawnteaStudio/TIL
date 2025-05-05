//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split('\n');

// cording here!!
let a = +input[0];
let res = 1;

while(a > 0){
  res *= a;
  a--;
}

console.log(res);

