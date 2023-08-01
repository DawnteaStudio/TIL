//basic setting
var fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

//split setting (what you want) (Must be "trim()")
var input = fs.readFileSync(filePath).toString().trim().split('\n');

//cording here

//변수 초기화
let node = +input[0].split(' ')[0];
let edge = +input[0].split(' ')[1];
let startingNode = +input[0].split(' ')[2];

let dfsResult = [];
let bfsResult = [];
let bfsQueue = [startingNode];
let visit = [];

//노드와 간선 구조를 정수형 2차원 배열로 변환
for(let i=1; i<input.length;i++){
  input[i] = input[i].split(' ').map(Number);
}

//dfs 함수
function dfs(start){
  visit.push(start);
  dfsResult.push(start);
  let anotherNodes = [];

  for(let i=1; i<input.length;i++){

    if(input[i].includes(start)){
      anotherNodes.push(input[i].indexOf(start) === 0 ? input[i][1] : input[i][0]);
    }
  }

  anotherNodes = anotherNodes.sort((a,b) => a-b);
  for(let i of anotherNodes){
    if(visit.includes(i)){
      continue
    }else{
      dfs(i)
    }
  }

}

//bfs 함수
function bfs(Queue){
  if(Queue.length == 0){
    return;
  }

  let start = bfsQueue.shift();
  let anotherNodes = [];

  visit.push(start);
  bfsResult.push(start);

  for(let i=1;i<input.length;i++){
    if(input[i].includes(start)){
      anotherNodes.push(input[i].indexOf(start) === 0 ? input[i][1] : input[i][0]);
    }
  }
  anotherNodes = anotherNodes.sort((a,b) => a-b);

  for(let i of anotherNodes){
    if(! (visit.includes(i) || bfsQueue.includes(i)) ) {
      bfsQueue.push(i);
    }
  }
  bfs(bfsQueue);
}

dfs(startingNode);
visit = [];
bfs(bfsQueue);

dfsResult = dfsResult.join(' ');
bfsResult = bfsResult.join(' ');

console.log(dfsResult);
console.log(bfsResult);