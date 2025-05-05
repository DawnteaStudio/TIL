var readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});
//split setting (what you want)
let input = [];
let quad;

rl.on('line', function(line) {
    input .push(line);
    // cording here!!
let a = +input[0];
let b = +input[1];
if(a < 0){
  b > 0 ?  quad = 2 : quad = 3;
}else{
  b > 0 ? quad = 1 : quad = 4;
}

}).on("close", function() {
  console.log(quad);
  process.exit();
});
