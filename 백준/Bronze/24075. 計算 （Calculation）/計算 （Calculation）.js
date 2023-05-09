//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here
let sum = input[0] + input[1];
let diff = input[0] - input[1];

if(sum > diff){
  console.log(sum);
  console.log(diff);
}else{
  console.log(diff);
  console.log(sum);
}