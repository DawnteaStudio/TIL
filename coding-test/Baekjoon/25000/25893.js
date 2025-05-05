//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [cases, ...num] = input;

for(i=0;i<cases;i++){
  let nums = num[i].split(' ').map(Number);
  let cnt = 0;
  for(j=0;j<3;j++){
    if(nums[j] >= 10){
      cnt++;
  }
  }
  console.log(num[i]);
  cnt == 3 ? console.log("triple-double") : cnt == 2 ? console.log("double-double") : cnt == 1 ? console.log("double") : console.log("zilch");
  if(i !== cases - 1) console.log();
}