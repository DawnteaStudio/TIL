//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [num, ...cases] = input;
let str = '';

for(i=0;i<num;i++){
  let [a,...deno] = cases[i].split(' ').map(Number);
  let denominations = deno.join(' ');

  let first = deno[0];
  let status = "Good";
  for(j=1;j<a;j++){
    if(deno[j] < first*2){
      status = "Bad";
      break;
    }
    first = deno[j];
  }
  str += `Denominations: ${denominations}` + '\n';
  str += `${status} coin denominations!` + '\n' + '\n';
}

console.log(str.trim());