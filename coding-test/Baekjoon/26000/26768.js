//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim();

//cording here
let cyfra = { 
  a : 4,
  e : 3,
  i : 1,
  o : 0,
  s : 5};
let str = '';
for(i of input){
  if(Object.keys(cyfra).includes(i)){
    str+= cyfra[i];
  }else{
    str +=i;
  }
}

console.log(str);