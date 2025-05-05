//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);

//cording here
let[now,plus] = input;

if((now+plus)%12 == 0){
  console.log(12);
}else{
  console.log((now+plus)%12);
}
