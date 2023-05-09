//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().split(' ').map(Number);

//cording here
let [width, height] = input;

if(width%2 == 0 || height%2 == 0){
  console.log(0);
}else{
  width > height ? console.log(height) : console.log(width);
}