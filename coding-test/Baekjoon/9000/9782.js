//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let cases = [];
let cnt = 1;

for(i of input){
  let [N,...nums] = i.split(' ').map(Number);

  if(N%2 !== 0 & N !== 0){
    cases.push(nums[((N+1)/2)-1].toFixed(1));
  }else if(N !== 0){
    cases.push(((nums[N/2 - 1]+nums[N/2])/2).toFixed(1));
  }
}

for(i of cases){
  console.log(`Case ${cnt}: ${i}`);
  cnt++;
}