//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split('\n');

// cording here!!
let [num, test] = input;
let condition = parseInt(num.split(' ')[1]);
let str = '';

for(i of test.split(' ')){
  if(i < condition){
    str += i +" ";
  }
}

console.log(str.trim());
