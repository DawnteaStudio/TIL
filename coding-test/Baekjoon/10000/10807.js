//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split('\n');

// cording here!!
let [num, test] = input;
let condition = input[2];
let cnt = 0;

for(i of test.split(' ')){
  if(i == condition){
    cnt++;
  }
}

console.log(cnt);
