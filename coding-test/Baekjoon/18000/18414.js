//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here
let[x,l,r] = input;

if(x >= r){
  console.log(r);
}else if(x <= l){
  console.log(l);
}else{
  console.log(x);
}