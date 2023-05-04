const readline = require("readline");

const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

let input = [];

rl.on("line", (line)=>{
	input.push(line);
});

rl.on("close", () => {
  for(i=1;i<=input[0];i++){
    let [lt,wt,le,we] = input[i].split(' ').map(BigInt);
    lt*wt > le*we ? res = "TelecomParisTech" : lt*wt == le*we ? res = "Tie" : res = "Eurecom";
    console.log(res);
  }	process.exit();
  });