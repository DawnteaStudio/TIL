//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim();

//cording here
let sum = 0;
for(i = 1; i <= input; i++){
  sum += i**3;
}
console.log(sum);