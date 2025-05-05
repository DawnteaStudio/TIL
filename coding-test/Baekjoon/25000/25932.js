//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [cases, ...num] = input;
let twin = [];

for(i=0;i<cases;i++){
  let nums = num[i].split(' ').map(Number);
  console.log(num[i]);
  for(j=0;j<10;j++){
    if(nums[j] == 17){
      twin.push("zack");
    }else if(nums[j] == 18){
      twin.push("mack");
    }
    if(twin.length == 2) break;
  }
  twin.length == 2 ? console.log("both") : twin.length == 1 ? console.log(twin[0]) : console.log("none");
  if(i !== cases-1) console.log();
  twin = [];
}
