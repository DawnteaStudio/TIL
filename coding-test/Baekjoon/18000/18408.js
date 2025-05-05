//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here
let one = 0;
let two = 0;

for(i of input){
  if(i == 1){
    one++;
  }else{
    two++;
  }
}

if(one > two) console.log(1);
else console.log(2);