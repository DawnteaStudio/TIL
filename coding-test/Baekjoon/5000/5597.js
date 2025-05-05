//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split('\n');

// cording here!!
let result = [];
let i = 1;

while(i <= 30){
  if(!input.includes(`${i}`)){
    result.push(i)
  }
  i++;
}
result.sort((a,b) => a-b);

for(i of result){
  console.log(i);
}