//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let names = {};

for(i of input){
  let = [name, age, weight] = i.split(' ');
  if(name !== "#" && (age > 17 || weight >= 80)){
    names[name] = "Senior";
  }else if(name !== "#"){
    names[name] = "Junior";
  }
}
let keys = Object.keys(names);
for(i of keys){
  console.log(i, names[i]);
}