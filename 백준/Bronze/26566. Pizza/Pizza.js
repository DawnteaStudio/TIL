//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [num, ...cases] = input;
const Pi = Math.PI;
for(i=0;i<num;i++){
  let [wP,wD] = cases[0].split(' ').map(Number);
  let [sP,sD] = cases[1].split(' ').map(Number);
  wP/wD < (sP*sP*Pi)/sD ? console.log("Whole pizza") : console.log("Slice of pizza");
  cases = cases.slice(2);
}