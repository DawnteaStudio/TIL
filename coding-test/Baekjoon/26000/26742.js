//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim();

//cording here
let B = 0;
let C = 0;
let total = 0;
for(i of input){
  if(i == 'B') B++;
  else if(i == 'C') C++;
}

console.log(`${Math.floor(B/2)+Math.floor(C/2)}`);