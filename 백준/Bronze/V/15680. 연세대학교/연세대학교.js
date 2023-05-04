//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim();

//cording here
if(input == 0){
  console.log("YONSEI");
}else if(input == 1){
  console.log("Leading the Way to the Future");
}
