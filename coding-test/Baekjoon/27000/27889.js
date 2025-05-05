//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim();

//cording here
let list ={
  "NLCS": "North London Collegiate School",
  "BHA": "Branksome Hall Asia",
  "KIS": "Korea International School",
  "SJA": "St. Johnsbury Academy",
}

console.log(list[input]);