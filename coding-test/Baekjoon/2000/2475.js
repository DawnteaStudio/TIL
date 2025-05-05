//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split(' ');

let key = 0;

for(i of input){
  key += (+i)**2;
}

console.log(key%10);