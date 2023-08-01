//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [cases, num] = input;

let [...nums] = num.split(' ').map(Number);
let sum = 0;

for(i=0;i<cases;i++){
  sum += nums[i]**3;
}

console.log(Math.pow(sum,1/3));