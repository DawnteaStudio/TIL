//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let now = new Date();
let str = '';

let year = now.getFullYear().toString();
let month = (now.getMonth()+1).toString();
let date = now.getDate().toString();

if(month.length == 1) month = '0'+month;
if(date.length == 1) date = '0'+date;

str += year + '\n' + month + '\n' +date;
console.log(str);