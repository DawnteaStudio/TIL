//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(BigInt);

//cording here

let [rows, cols, num] = input;
let row = (num)/cols;
let col = (num)%cols;

console.log(`${row} ${col}`);