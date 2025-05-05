//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here
let [def, att] = input;

if(def - def*(att/100) >= 100){
  console.log(0);
}else{
  console.log(1);
}