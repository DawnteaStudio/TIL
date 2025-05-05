//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want)
var input = fs.readFileSync(filePath).toString().split('\n');

let [conditon, ...matrix] = input;
let row = conditon.split(' ')[0];
let column = conditon.split(' ')[1];

let matA = [];
let matB = [];
let sumMat = "";

for(i=0;i<row;i++){
  let [head, ...another] = matrix;
  head = head.split(' ');
  let columns = [];
  for(j=0;j<column;j++){
    columns.push(head[j]);
  }
  matA.push(columns);
  matrix = another;
}

for(i of matrix){
  let columns = [];
  i = i.split(' ');
  for(j=0;j<column;j++){
    columns.push(i[j]);
  }
  matB.push(columns);
}

for(i in matA){
  for(j in matA[i]){
    sumMat += (+matA[i][j]) + (+matB[i][j]) +' ';
  }
  sumMat += '\n';
}

console.log(sumMat.trim());