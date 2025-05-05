//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split('\n');

// cording here!!
let [num, ...caseArr] = input;
let stack = "";
for(i=0;i<num;i++){
  let [a,b] = caseArr[i].split(' ');
  stack += (`${Number(a)+Number(b)}\n`);
}

console.log(stack);