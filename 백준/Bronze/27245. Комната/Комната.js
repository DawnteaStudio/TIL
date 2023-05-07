//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);

//cording here
let [w,l,h] = input;
let long = 0;
let short = 0;

function checker(longer, shorter){
  long= longer;
  short = shorter;
}

w > l ? checker(w,l): checker(l,w);

if(short/h >= 2){
  if(long/short <= 2){
    console.log("good");
  }else{
    console.log("bad");
  }
}else{
  console.log("bad");
}