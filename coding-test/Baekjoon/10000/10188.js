//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [limit, ...cases] = input;

for(i=0;i<limit;i++){
  let [column,row] = cases[i].split(' ').map(Number);
  for(j=0;j<row;j++){
      console.log("X".repeat(column));
    }
  if(i !== limit-1)
    console.log();
  }