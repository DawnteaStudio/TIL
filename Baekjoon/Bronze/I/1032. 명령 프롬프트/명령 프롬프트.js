//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
var input = fs.readFileSync(filePath).toString().split('\n').map(e => e.trim());

//cording here
let count = input[0];
let result = input[1];

for(i = 2; i <= count;i++){
    let stack = "";
    for(j=0;j<input[i].length;j++){
        if(result[j] == input[i][j])
            stack += result[j];
        else{
            stack += "?";
        }
    }
    result = stack;
}

console.log(result);