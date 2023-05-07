//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim();

//cording here
let A = 0;
let B = 0;
for(i of input){
  if(i == 'A') A++;
  else if(i == 'B') B++;
}

console.log(`${A} : ${B}`);