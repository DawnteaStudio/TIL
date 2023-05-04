//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [num, ...pwd] = input;
for(i of pwd){
  if(i.length >= 6 && i.length <= 9){
    console.log('yes');
  }else{
    console.log('no');
  }
}