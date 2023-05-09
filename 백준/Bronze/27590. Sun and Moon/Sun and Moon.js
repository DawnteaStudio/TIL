//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let [sun,moon] = input;
let [sunD,sunY] = input[0].split(' ').map(Number);
let [moonD,moonY] = input[1].split(' ').map(Number);
let cnt = 0;
let sunPer = sunY*cnt + (sunY-sunD)-(moonY-moonD);

while(sunPer%moonY !== 0){
  cnt++;
  sunPer = sunY*cnt + (sunY-sunD)-(moonY-moonD);
}

console.log(sunY*cnt + (sunY-sunD));