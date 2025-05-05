//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [cases, ...Case] = input;
let str = '';

for(i = 0; i<cases; i++){
  let [column, row] = Case[i].split(' ').map(Number);
  str += (column%2 == 0 ? column/2 *row : (column-1)/2 *row + Math.floor(row/2)) + '\n';
}

console.log(str.trim());