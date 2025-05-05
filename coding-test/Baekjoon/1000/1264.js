//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let check = ['a', 'e', 'i', 'o', 'u'];
for(i of input){
  if(i !== '#'){
    let cnt = 0;
    for(j of i){
      if(check.includes(j.toLowerCase())){
        cnt++;
      }
    }
    console.log(cnt);
  }
}