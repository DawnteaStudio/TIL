//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);

//cording here
let[s,a,b] = input;
let price = 250;
if(s>a){
  console.log(price + 100*Math.ceil((s-a)/b));
}else{
  console.log(price);
}
