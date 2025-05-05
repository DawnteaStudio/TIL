//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
let input = require('fs').readFileSync(filePath).toString().trim().split('\n');

//cording here
let len = +input.shift();
let nums = input.shift().split(' ').map(Number);

let max = nums[0];
let plus = 0;

for(let i = 0; i < len; i++){
    if(nums[i] > 0){
        plus += nums[i];
        if(plus > max){
            max = plus;
        }
    }else{
        plus += nums[i];
        if(plus < 0){
            plus = 0
        }
        if(max < 0 && nums[i] > max){
            max = nums[i];
        }
    }
}

console.log(max);
