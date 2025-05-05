//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('').map(Number);

//cording here
let line1 = ['0000', '   1', '2222', '3333', '4  4', '5555', '6666', '7777', '8888', '9999'];
let line2 = ['0  0', '   1', '   2', '   3', '4  4', '5', '6', '   7', '8  8', '9  9'];
let line3 =  ['0  0', '   1', '2222', '3333', '4444', '5555', '6666', '   7', '8888', '9999'];
let line4 =  ['0  0', '   1', '2', '   3', '   4', '   5', '6  6', '   7', '8  8', '   9'];
let line5 = ['0000', '   1', '2222', '3333', '   4', '5555', '6666', '   7', '8888', '   9']; 
let str = '';
for(i of input){
  str +=line1[i] + '\n';
  str +=line2[i]+ '\n';
  str +=line3[i]+ '\n';
  str +=line4[i]+ '\n';
  str +=line5[i]+ '\n' +'\n';
}

console.log(str.trim());