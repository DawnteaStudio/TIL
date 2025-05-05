//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim();

//cording here
function fact(num){
  if(num <= 1){
    return 1;
  }else{
    return num * fact(num-1);
  }
}

console.log(fact(+input));