//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
var input = fs.readFileSync(filePath).toString().split('\n').map(e => e.trim());

//cording here
let count = input[0];
let result = "";

for (let i = 1; i <= count; i++) {
    let a = +input[i].split(" ")[0] % 10;
    let b = +input[i].split(" ")[1];

    if (a == 1 || a == 5 || a == 6) {
        result += a + '\n';
    } else if (a == 0) {
        result += 10 + '\n';
    } else if (a == 4 || a == 9) {
        switch (b % 2) {
            case 1:
                result += a + '\n'
                break;
            case 0:
                result += (a ** 2) % 10 + '\n';
                break;
        }
    } else {
        switch (b % 4) {
            case 1:
                result += a + '\n'
                break;
            case 2:
                result += (a ** 2) % 10 + '\n';
                break;
            case 3:
                result += (a ** 3) % 10 + '\n';
                break;
            case 0:
                result += (a ** 4) % 10 + '\n';
                break;
        }
    }
}

console.log(result.trim());