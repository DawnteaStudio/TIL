//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
let input = require('fs').readFileSync(filePath).toString().trim().split('\n').map(e=> e.trim());

//cording here
let [N, M] = input.shift().split(' ').map(Number);
let trees = input.shift().split(' ').map(Number);

let min = 1;
let max = trees.sort((a,b) => a-b)[trees.length-1];
let mid = Math.floor((min+max)/2);

while(min <= max){
    let tree = 0;
    mid = Math.floor((min+max)/2);
    
    for(let i = 0; i < N; i++){
        if(trees[i] > mid){
            tree += trees[i] - mid;
        }
    }

    tree >= M ? (min = mid + 1) : (max = mid - 1);
}

console.log(max);