//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here
let str = ''

for(i=1;i<=input;i++){
  if(i%7==0){
    if(i%11 == 0){
      str += "Wiwat!" +'\n';
    }else{
      str += 'Hurra!' + '\n';
    }
  }else{
    if(i%11 == 0){
      str += "Super!" + '\n';
    }else{
      str += i + '\n';
    }
  }
}

console.log(str.trim());