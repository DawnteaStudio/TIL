//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here

let origin = '';
let missa = '';
let cnt = 0;

let [head, ...images] = input;
let [row, col] = head.split(' ').map(Number);

for(i =0; i<row;i++){
  origin += images[i];
}

for(i = 1; i <= row; i++){
  missa += images[row + i];
}

for(i=0;i<origin.length;i++){
  if(origin[i] == missa[i]){
    cnt++;
  }
}

console.log(cnt);