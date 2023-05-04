//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split('\n');

//cording here
let str = '';

for(i of input){
  str += i + '\n'
}

console.log(str.trim());

