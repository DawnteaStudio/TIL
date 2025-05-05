//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let str = '';

for(i of input){
  for(j=0;j<i.length;j++){
    if(i[j].charCodeAt()== 101 ||i[j].charCodeAt() == 69){
      str += String.fromCharCode(i[j].charCodeAt()+4);
    }else if(i[j].charCodeAt()== 105 ||i[j].charCodeAt() == 73){
      str += String.fromCharCode(i[j].charCodeAt()-4);
    }else{
      str += i[j];
    }
  }
  str += '\n';
}

console.log(str.trim());