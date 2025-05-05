//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
var input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);

//cording here
let [_, ...nums] = input;
let sum = 0;
for(i of nums){
  sum += i;
}
console.log(sum);