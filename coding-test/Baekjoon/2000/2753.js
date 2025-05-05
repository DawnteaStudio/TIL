//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split(' ');

// cording here!!
let a = +input[0];

if((a % 4 == 0 && a%100 !== 0) || a%400 == 0){
  console.log(1);
}else{
  console.log(0);
}