//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let score = [6,3,2,1,2];
let [a,b] = input;
let str ='';

for(i in input){
  let sum = 0;
  for(j = 0; j< score.length; j++){
    sum += score[j]*input[i].split(' ')[j]
  }
  str += sum + ' ';
}

console.log(str.trim());
