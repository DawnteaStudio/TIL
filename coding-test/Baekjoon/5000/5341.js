//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);

//cording here
let result = [];

for(i of input){
  let sum = 0;
  for(let j =1;j<=i;j++ ){
    sum += j;
  }
  if(i)
    result.push(sum);
}

console.log(result.join('\n'));