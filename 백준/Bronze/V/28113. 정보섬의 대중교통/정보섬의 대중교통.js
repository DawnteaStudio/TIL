//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(" ").map(Number);

//cording here
let bus = input[1];
let subway = input[2];

bus > subway ? console.log("Subway") :
bus < subway ? console.log("Bus") : console.log("Anything");