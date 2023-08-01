//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let form = {CU:	"see you",
  ":-)"	: "I’m happy",
  ":-("	: "I’m unhappy",
  ";-)":	"wink",
  ":-P"	: "stick out my tongue",
  "(~.~)"	: "sleepy",
  TA	: "totally awesome",
  CCC :	"Canadian Computing Competition",
  CUZ	: "because",
  TY :	"thank-you",
  YW :"you’re welcome",
  TTYL:"talk to you later"}

for(i of input){
  if(Object.keys(form).includes(i)){
    console.log(form[i]);
  }else{
    console.log(i);
  }
}
