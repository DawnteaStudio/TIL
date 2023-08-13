//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
let input = require('fs').readFileSync(filePath).toString().trim().split('\n').map(e=> e.trim());

//cording here
let [N, M] = input.shift().split(' ').map(BigInt)
let inspectors = input.map(BigInt);

let min = 1n;
let max = 10n ** 9n*M;
let mid, cnt;
while(max >= min){
    cnt = 0n;
    mid = (min+max)/2n;
    
    for(let i = 0; i < N; i++){        
        cnt += mid/inspectors[i];
    }
    M <= cnt ? (max = mid - 1n) : (min = mid + 1n);
}

console.log(String(min));