//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [total, num, ...prod] = input;
let sum = 0;
for(i of prod){
  let [a,b] = i.split(' ').map(Number);
  sum += a*b;
}

sum == total ? console.log("Yes") : console.log("No");