//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here
let [a,b,c] = input;

if(c>=a && c < b){
  console.log(1);
}else{
  console.log(0);
}
