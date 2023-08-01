//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim();

//cording here
switch (input) {
  case "SONGDO":
    console.log("HIGHSCHOOL");
    break;
  case "CODE":
    console.log("MASTER");
    break;
  case "2023":
    console.log("0611");
    break;
  case "ALGORITHM":
    console.log("CONTEST");
    break;
}