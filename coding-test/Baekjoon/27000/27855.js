//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [a,b] = input;
let arrA = a.split(' ').map(Number);
let arrB = b.split(' ').map(Number);

let [scoreA, scoreB] = [arrA[0]*3+arrA[1],arrB[0]*3+arrB[1] ];

if(scoreA == scoreB) console.log("NO SCORE");
else
scoreA>scoreB ? console.log(1, scoreA-scoreB) : console.log(2, scoreB-scoreA);