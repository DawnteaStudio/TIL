//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().trim().split('\n')

//cording here
let result = "";

for(i of input){
  let [person, shares] = i.split(' ').map(elem => BigInt(elem));
  result += shares/(person+BigInt(1)) + '\n';
}

console.log(result.trim());