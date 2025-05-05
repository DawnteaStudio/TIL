//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim();

//cording here
let output = '';
let index = 0;

while(index < input.length){
  output += input[index];
  let unicode = input[index].charCodeAt();
  index += unicode-64;
}

console.log(output);