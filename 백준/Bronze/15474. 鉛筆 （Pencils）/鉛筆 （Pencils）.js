//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here
let [total, x, priceX, y,priceY] = input;

let price = Math.ceil(total/x) * priceX < Math.ceil(total/y) * priceY ? Math.ceil(total/x) * priceX : Math.ceil(total/y) * priceY;

console.log(price);