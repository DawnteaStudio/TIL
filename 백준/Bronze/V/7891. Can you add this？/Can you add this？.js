//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let testNumber = input[0];
let result = [];

for(i=1; i<=testNumber;i++){
  let [head, tail] = input[i].split(' ').map(BigInt);
  result.push(head+tail);
}

console.log(result.join('\n'));
