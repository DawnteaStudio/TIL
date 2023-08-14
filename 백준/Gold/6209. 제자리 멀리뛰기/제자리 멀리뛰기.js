//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
let input = require('fs').readFileSync(filePath).toString().trim().split('\n').map(e => e.trim());

//cording here
let [d, n, m] = input.shift().split(' ').map(BigInt)
let islands = input.sort((a, b) => a - b).map(BigInt);
islands.push(d);
let min = 0n, max = d;
let mid = (min + max)/2n;

while(min <= max){
    let cnt = 0n;
    let prev = 0n;
    mid = (min + max)/2n;

    for(let i = 0; i < islands.length; i++){
        if(islands[i] < prev + mid){
            cnt++;
        }else{
            prev = islands[i];
        }
    }
    cnt > m ? (max = mid -1n) : (min = mid + 1n);
}

console.log(max.toString());