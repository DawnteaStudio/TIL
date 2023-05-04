//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim();

//cording here
let str= `#  # #### #### #  #
#### #  # #  # # #
#### #  # #  # # #
#  # #### #### #  #`

console.log(str);