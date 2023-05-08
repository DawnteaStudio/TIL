//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n')[1];

//cording here

if(input[input.length-1] == 'G'){
  let str = [];
  let result = '';
  for(i of input){
    str.push(i);
  }
  str.pop();
  for(i of str){
    result += i;
  }
  console.log(result);
}else{
  console.log(input +'G');
}