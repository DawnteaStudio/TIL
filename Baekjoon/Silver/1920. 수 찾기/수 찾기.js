//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
const input = require('fs').readFileSync(filePath).toString().trim().split('\n').map(e => e.trim());

//cording here
let N = Number(input[0]);
let caseArr = input[1].split(' ').map(Number).sort((a, b) => a - b);
let M = Number(input[2]);
let testArr = input[3].split(' ').map(Number);
let result = [];

function binSearch(start, end, num) {
    if (start > end) {
        return;
    }

    let mid = Math.floor((start + end) / 2);
    if (caseArr[mid] === num) {
        result.push(1);
        return;
    }

    if (caseArr[mid] > num) {
        binSearch(start, mid - 1, num);
    } else {
        binSearch(mid + 1, end, num);
    }
}

for (let i = 0; i < M; i++) {
    binSearch(0, N - 1, testArr[i]);
    if(result.length !== i+1){
        result.push(0);
    }
}

console.log(result.join('\n'));