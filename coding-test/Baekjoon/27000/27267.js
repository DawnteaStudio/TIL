//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().split(' ').map(Number);

//cording here
let [a,b,c,d] = input;

a*b > c*d ? console.log('M') : a*b < c*d ? console.log('P') : console.log('E');