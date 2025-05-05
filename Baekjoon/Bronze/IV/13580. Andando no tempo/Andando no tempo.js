//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here
let set = new Set(input);

if(set.size <= 2){
  console.log("S");
}else{
  input = input.sort((a,b) => a-b);
  if(input[0]+input[1] == input[2]){
    console.log("S");
  }else{
    console.log("N");
  }
}
