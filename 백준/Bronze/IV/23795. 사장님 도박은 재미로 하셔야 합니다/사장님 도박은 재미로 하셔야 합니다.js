//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);

//cording here
let result = 0;

for(i of input){
  if(i == -1){
    break;
  }
  result += i;
}

console.log(result);