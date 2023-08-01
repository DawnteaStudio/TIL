//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
const input = require('fs').readFileSync(filePath).toString().trim().split('\n');

//cording here
let line = Number(input.shift());
let graph = input.map((v) => v.trim().split(''));
let visit = Array.from(Array(line), () => Array(line).fill(false));
let rgdiff = 0;
let rgsame = 0;

let drow = [-1, 0, 1, 0];
let dcol = [0, -1, 0, 1];

function dfsR(row, column) {
    for (let i = 0; i < 4; i++) {
        let newRow = row + drow[i];
        let newCol = column + dcol[i];

        if (newRow < 0 || newCol < 0 || newRow >= line || newCol >= line) {
            continue;
        }

        if (graph[newRow][newCol] == 'R' && visit[newRow][newCol] == false) {
            visit[newRow][newCol] = true;
            dfsR(newRow, newCol);
        }
    }
}
function dfsG(row, column) {
    for (let i = 0; i < 4; i++) {
        let newRow = row + drow[i];
        let newCol = column + dcol[i];

        if (newRow < 0 || newCol < 0 || newRow >= line || newCol >= line) {
            continue;
        }

        if (graph[newRow][newCol] == 'G' && visit[newRow][newCol] == false) {
            visit[newRow][newCol] = true;
            dfsG(newRow, newCol);
        }
    }
}
function dfsB(row, column) {
    for (let i = 0; i < 4; i++) {
        let newRow = row + drow[i];
        let newCol = column + dcol[i];

        if (newRow < 0 || newCol < 0 || newRow >= line || newCol >= line) {
            continue;
        }

        if (graph[newRow][newCol] == 'B' && visit[newRow][newCol] == false) {
            visit[newRow][newCol] = true;
            dfsB(newRow, newCol);
        }
    }
}
function dfsRG(row, column) {
    for (let i = 0; i < 4; i++) {
        let newRow = row + drow[i];
        let newCol = column + dcol[i];

        if (newRow < 0 || newCol < 0 || newRow >= line || newCol >= line) {
            continue;
        }

        if ((graph[newRow][newCol] == 'R' || graph[newRow][newCol] == 'G') && visit[newRow][newCol] == false) {
            visit[newRow][newCol] = true;
            dfsRG(newRow, newCol);
        }
    }
}

function dfsRGB() {
    let cnt = 0;
    for (let row = 0; row < line; row++) {
        for (let column = 0; column < line; column++) {
            if (visit[row][column] == false) {
                switch (graph[row][column]) {
                    case 'R':
                        cnt++;
                        visit[row][column] = true;
                        dfsR(row, column);
                        break;
                    case 'G':
                        cnt++;
                        visit[row][column] = true;
                        dfsG(row, column);
                        break;
                    case 'B':
                        cnt++;
                        visit[row][column] = true;
                        dfsB(row, column);
                        break;
                }
            }
        }
    }

    rgdiff = cnt;
}

function dfsRB() {
    let cnt = 0;
    for (let row = 0; row < line; row++) {
        for (let column = 0; column < line; column++) {
            if (visit[row][column] == false) {
                switch (graph[row][column]) {
                    case ('G'):
                        cnt++;
                        visit[row][column] = true;
                        dfsRG(row, column);
                        break;
                    case 'B':
                        cnt++;
                        visit[row][column] = true;
                        dfsB(row, column);
                        break;
                }
            }
        }
    }

    rgsame = cnt;
}

// function reset() {
//     visit = [];
//     for (let row = 1; row <= line; row++) {
//         let rowVisit = [];
//         for (let column = 1; column <= line; column++) {
//             rowVisit.push(false);
//         }
//         visit.push(rowVisit);
//     }
// }
dfsRGB();
visit = Array.from(Array(line), () => Array(line).fill(false));
for (let i = 0; i < line; i++) {
    for (let j = 0; j < line; j++) {
      if (graph[i][j] == 'R') graph[i][j] = 'G';
    }
  }
dfsRB();

console.log(rgdiff+" "+rgsame);

