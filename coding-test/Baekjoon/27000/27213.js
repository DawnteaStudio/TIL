//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);

//cording here
let [row,column] = input;

if(row==1){
  console.log(column);
}else if(column==1){
  console.log(row);
}else{
  console.log(row*2+column*2 -4);
}