//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here
let [home, ele, stair, eleva] = input;

console.log((home-1)*eleva+(ele-1)*eleva,(home-1)*stair);