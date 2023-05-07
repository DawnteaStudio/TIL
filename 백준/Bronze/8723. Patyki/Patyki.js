//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split(' ').map(Number);

//cording here
input = input.sort((a,b) => b-a);
let [a,b,c] = input;

if(a**2 == b**2 + c**2){
  console.log(1);  
}else if(a==b && b==c){
  console.log(2);
}else{
  console.log(0);
}
