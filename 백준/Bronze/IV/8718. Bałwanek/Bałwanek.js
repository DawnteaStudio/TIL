//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number).map((elem => elem*1000));

//cording here
let k = input[1];
let snow = input[0];
let [big, medium, small] = [k+k*2+k*4,k*2+k+k/2, k+k/2+k/4];

big <= snow ? console.log(big) : 
medium <= snow ? console.log(medium) : 
small <= snow ? console.log(small) : 
console.log(0);