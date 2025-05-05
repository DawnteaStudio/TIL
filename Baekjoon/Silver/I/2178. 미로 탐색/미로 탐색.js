//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
// input 유형 별로 split(공백 or 줄바꿈) 뒤에 붙이시면 됩니다.!!
var input = fs.readFileSync(filePath).toString().split('\n').map(e => e.trim());

//cording here
let [row, column] = input[0].split(' ').map(Number);
let graph = [];
let visit = [];
let dx = [-1, 0, 1, 0];
let dy = [0, -1, 0, 1];
let bfsQueue =[[0,0,1]];
let goal = [];

function bfs(graph,visit){
    let [x,y,len] = bfsQueue.shift();

    if(graph[y][x] == 1 && visit[y][x] == false){
        visit[y][x] = true;

        for(let i = 0; i < 4; i++){
            let newX = x+dx[i];
            let newY = y+dy[i];
            if(newX < 0 || newY < 0 || newX >= column || newY >= row){
                continue;
            }
            if(newX == column-1 && newY == row-1){
                goal.push(len+1);
            }
            if(graph[newY][newX] == 1 && visit[newY][newX] == false){
                bfsQueue.push([newX,newY,len+1]);
            }
        }
    }
}

for(let i = 0; i<row; i++){
    let rowGraph = input[i+1].split('').map(Number);
    let rowVisit = [];
    for(let j = 0; j<column; j++){
        rowVisit.push(false);
    }
    graph.push(rowGraph);
    visit.push(rowVisit);
}

while(bfsQueue.length > 0){
    bfs(graph,visit);
}

console.log(goal.sort((a,b) => a-b)[0]);
