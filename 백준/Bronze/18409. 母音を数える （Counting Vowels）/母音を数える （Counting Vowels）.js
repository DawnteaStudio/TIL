//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let test = ["a","i","u","e","o"];
let str = input[1];
let cnt = 0;

for(i of str){
  if(test.includes(i)) cnt++;
}

console.log(cnt);