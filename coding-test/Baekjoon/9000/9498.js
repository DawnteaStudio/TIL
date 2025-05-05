//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split(' ');

// cording here!!
let a = +input[0];
let score = ["F","D","C","B","A","A"];
let cnt = 0;

while(a-60 >= 0){
  cnt++;
  a -= 10;
}

console.log(score[cnt]);