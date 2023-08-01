//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ');

//cording here
let [a,plus,b,equal,result] = input;
if((+a)+(+b) == result) console.log("YES");
else console.log("NO");