//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let[num, ...cases] = input;

for(i=0; i< num;i++){
  let [a,b] = cases[i].split(' ').map(Number);
  if(a+b > 3){
    console.log('No');
  }else{
    if(a !== 3 && b !==3){
      console.log('Yes');
    }else{
      console.log('No');
    }
  }
}