//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split('\n');

//cording here
let [num, ...str] = input;
let result = '';
for(i=0;i<num;i++){
  result += str[i][0]+str[i][str[i].length-1]+'\n';
}
console.log(result.trim());
