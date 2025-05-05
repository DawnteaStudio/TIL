var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

var input = fs.readFileSync(filePath).toString().trim();

const radius = Math.sqrt(+input / Math.PI); 
const perimeter = 2 * Math.PI * radius; // 원의 둘레 계산

console.log(perimeter.toFixed(6));