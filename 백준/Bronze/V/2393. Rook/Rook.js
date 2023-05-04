//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split('\n');

//cording here
let str = `  ___  ___  ___
  | |__| |__| |
  |           |
   \\_________/
    \\_______/
     |     |
     |     |
     |     |
     |     |
     |_____|
  __/       \\__
 /             \\
/_______________\\`

console.log(str);