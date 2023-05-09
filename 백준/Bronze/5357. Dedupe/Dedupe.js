//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [cases, ...Case] = input;
let answer = [];

for(i = 0; i<cases; i++){
  let str = Case[i][0]
  for(j of Case[i]){
    if(str[str.length-1] !== j){
      str += j;
    }
  }
  answer.push(str);
}

for(i of answer){
  console.log(i);
}