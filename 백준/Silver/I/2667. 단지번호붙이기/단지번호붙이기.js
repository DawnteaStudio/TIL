//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
var input = fs.readFileSync(filePath).toString().split('\n').map(e => e.trim());

//cording here
let line = Number(input[0]);
let graph = [];
let visit = [];
let cnt = 0;
let dfsCnt = 0;
let result = [];

let drow = [-1, 0, 1, 0];
let dcol = [0, -1, 0, 1];

function dfs(row, column){
     for(let i = 0; i < 4; i++){
        let newRow = row + drow[i];
        let newCol = column + dcol[i];

        if(newRow<0 || newCol<0 || newRow >= line || newCol >= line){
            continue;
        }

        if(graph[newRow][newCol] == 1 && visit[newRow][newCol] == false){
            visit[newRow][newCol] = true;
            dfs(newRow,newCol);
        }
    }
    dfsCnt++;
}

for(let row = 1; row <= line; row++){
    let rowGraph = input[row].split('').map(Number);
    let rowVisit = [];
    for(let column = 1; column <= line; column++){
        rowVisit.push(false);
    }
    graph.push(rowGraph);
    visit.push(rowVisit);
}

for(let row = 0; row < line; row++){
    for(let column = 0; column < line; column++){
        if(graph[row][column] == 1 && visit[row][column] == false){
            visit[row][column] = true;
            cnt++;
            dfsCnt = 0;
            dfs(row,column);
            result.push(dfsCnt);
        }
    }
}

console.log(cnt);
result.sort((a,b) => a-b);
for(i of result){
    console.log(i);
}