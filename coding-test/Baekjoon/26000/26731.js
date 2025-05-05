//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('');

//cording here

let Alpha = 0;
let cnt = 1;
for(i = 65; i < 91;i++){
  Alpha += i;
}
for(i of input){
  Alpha -= i.charCodeAt();
}

console.log(String.fromCharCode(Alpha));