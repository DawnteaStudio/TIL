//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().split(' ').map(Number);

//cording here
let [cm, neededCm, upCm] = input;

console.log(Math.ceil((neededCm-cm)/upCm));