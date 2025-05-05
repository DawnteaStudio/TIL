//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
let input = require('fs').readFileSync(filePath).toString().trim().split('\n').map(Number);

//cording here
let nums = input.shift();

while (input.length > 0) {
    let floor, unit;
    let stack = [1];
    let result = 0;
    [floor, unit, ...input] = input;

    for(let i = 0; i < floor; i++){
        for(let j = 1; j < unit; j++){
            if(i == 0){
                stack.push(j+1);
            }else{
                stack[j] += stack[j-1]; 
            }
        }
    }
    for(i of stack){
        result += i;
    }
    
    console.log(result);
}

