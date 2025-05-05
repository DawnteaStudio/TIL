//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split(' ').map(Number);

//cording here
let chess = [1,1,2,2,2,8];

let result = input.map((elem, i) => {
  return chess[i] - elem
})

console.log(result.join(' '));