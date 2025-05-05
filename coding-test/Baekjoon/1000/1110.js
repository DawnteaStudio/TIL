//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
const input = require('fs').readFileSync(filePath).toString().trim();

//cording here
let num = +input;
let cycle = 0;
do{
    let [head, tail] = [Math.floor(num/10),num%10];
    num = tail*10 + (head + tail)%10;

    cycle++;
}while(num !== +input);

console.log(cycle);