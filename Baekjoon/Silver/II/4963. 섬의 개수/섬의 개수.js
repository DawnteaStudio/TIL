//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here
let dx = [-1, -1, -1, 0, 0, 1, 1, 1];
let dy = [-1, 0, 1, -1, 1, -1, 0, 1];
let result = [];

function dfs(x,y,graph,visit){

  for(let i = 0; i<8;i++){
    let newX = x + dx[i];
    let newY = y + dy[i];
    if(newX < 0 || newY < 0 || newX >= graph[0].length || newY >= graph.length){
      continue;
    }

    if(graph[newY][newX] == 1 && visit[newY][newX] == false){
      visit[newY][newX] = true;
      dfs(newX,newY,graph,visit);
    }
  }
}

for(let i=0;i<input.length;i++){
  let x = input[i].split(" ").map(Number)[0];
  let y = input[i].split(" ").map(Number)[1];
  let lands = 0;

  if(x==0 && y==0)
    break;

  let visit = [];
  let graph = [];

  for(let j = 1; j <= y; j++){
    let visitConstrut = [];
    graph.push(input[i+j].split(" ").map(Number));

    for(let k =0; k < x; k++){
      visitConstrut.push(false);
    }
    visit.push(visitConstrut);
  }

  for(let Y = 0; Y < y; Y++){
    for(let X = 0; X < x; X++){
      if(graph[Y][X] == 1 && visit[Y][X] == false){
        visit[Y][X] = true;
        lands++;
        dfs(X,Y,graph,visit);
      }
    }
  }
  result.push(lands);
  i += y;
}

for(i of result){
  console.log(i);
}
