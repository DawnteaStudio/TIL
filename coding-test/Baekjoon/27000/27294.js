//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here
let [time, alco] = input;

if(alco ==0 && 12 <=time && time <= 16 ){
  console.log(320);
}else{
  console.log(280);
}