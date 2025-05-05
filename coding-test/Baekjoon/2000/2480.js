//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here
let cnt = {};

for(i of input){
  if(!(Object.keys(cnt).includes(String(i)))){
    cnt[i] = 1;
  }else{
    cnt[i] = cnt[i]+1;
  }

}
function calc(obj){
  for(i of Object.keys(obj)){
    if(obj[i] == 3){
      return i*1000+10000;
    }
    if(obj[i] == 2){
      return i*100+1000;
    }
  }
  return Object.keys(obj).sort((a,b) => b-a)[0]*100;
}

console.log(calc(cnt));