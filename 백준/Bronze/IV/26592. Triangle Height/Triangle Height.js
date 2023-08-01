//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [num, ...cases] = input;
for(i=0;i<num;i++){
  let [a,len] = cases[i].split(' ').map(Number);
  let height = ((2*a)/len).toFixed(2);
  console.log(`The height of the triangle is ${height} units`);
}