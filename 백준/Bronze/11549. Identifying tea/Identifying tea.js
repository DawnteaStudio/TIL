//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let tea = Number(input.shift());

let members = input[0].split(' ').map(Number);
let result = 0;

for(i of members){
  if(i == tea)
    result++;
}

console.log(result);
