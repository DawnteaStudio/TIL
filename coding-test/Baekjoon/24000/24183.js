//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here
let c4 = 0.229*0.324*2;
let a3 = 0.297*0.420*2;
let a4 = 0.210*0.297;

let [cc4,aa3,aa4] = input;

console.log(cc4*c4 + aa3*a3 + aa4*a4);