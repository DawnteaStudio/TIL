//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let colorList = ["black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"];
let firstRes = input[0];
let secondRes = input[1];
let thirdRes = input[2];

let result = (String(colorList.indexOf(firstRes.trim()))+String(colorList.indexOf(secondRes.trim())))*(10**colorList.indexOf(thirdRes));
console.log(result);