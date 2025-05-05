//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here

let [a,b] = input;

a*7 > b*13 ? console.log('Axel') : a*7 < b*13 ? console.log('Petra') : console.log('lika');