//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().trim();

//cording here
let table = {
  "A" : 4,
  "B" : 3,
  "C" : 2,
  "D" : 1,
  "F" : 0.0,
  "+" : 0.3,
  "-" : -0.3,
  "0" : 0.0,
}
let score = 0.0;
if(!(input[0] == 'F')){
  score = table[input[0]] + table[input[1]];
}
console.log(score.toFixed(1));