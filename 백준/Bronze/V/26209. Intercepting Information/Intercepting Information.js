//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here
let bit = true;
for(i of input){
  if(i == 9){
    bit = false;
    console.log("F");
    break;
  }
}
if(bit) console.log("S");