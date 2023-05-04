//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().trim();

//cording here
let str= "";

for(i of input){
  if(i.charCodeAt() <= 'Z'.charCodeAt()){
    str += i.toLowerCase();
  }else{
    str += i.toUpperCase();
  }
}
console.log(str);