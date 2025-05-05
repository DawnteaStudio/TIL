//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let[a,c,e] = input[0].split(' ').map(Number);
let[a_,c_,e_] = input[1].split(' ').map(Number);

let score = 'E';

if(c_ == c){
  score = 'C';
  if(a_ == a){
    score = 'A';
  }else if(a_ >= a/2){
    score = 'B';
  }
}else{
  if(c_ >= c/2){
    score = 'D'
  }
}

console.log(score);