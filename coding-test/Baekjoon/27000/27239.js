//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim();

//cording here
let columns = ['h','a','b','c','d','e','f','g'];

let row = Math.ceil(+input/8);
let column = columns[+input%8];

console.log(column+row);