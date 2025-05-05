//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
let input = require('fs').readFileSync(filePath).toString().trim().split('\n').map(e => e.trim());

//cording here
let chess = [];
let cnt = 0;

for(let i of input){
    chess.push(i.split(''));
}

for(let i = 0; i < chess.length; i++){
    for(let j = 0; j <chess[i].length; j++){
        if((i+j)%2 == 0 && chess[i][j] == 'F'){
            cnt++;
        }
    }
}

console.log(cnt);