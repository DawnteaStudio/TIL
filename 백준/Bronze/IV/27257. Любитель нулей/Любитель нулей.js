//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim();

//cording here

let cnt = 0;
for(i of input){
  if(i == '0'){
    cnt++;
  }
}

for(i=input.length-1;i >= 0; i--){
  if(input[i] !== '0') break;
  cnt--;
}
console.log(cnt);