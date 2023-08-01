//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().split('\n')[1].split('').map(Number);

//cording here
let sum = 0;
for(i of input){
  sum += i;
}

console.log(sum);