//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [t,n,...cases] = input;

for (let i = 0; i < t; i++){
  for(j=0;j<n;j++){
    let [a,b] = cases[j].split(' ').map(Number);
    console.log(`${a+b} ${a*b}`);
  }
  [n,...cases] = cases.slice(n);
}