function solution(answers) {
    var answer = [];
    let score = [0,0,0];
    let one = [1,2,3,4,5];
    let two = [1,3,4,5];
    let three = [3,1,2,4,5];
        
    for(i=0;i<answers.length;i++){
        //one
        if(one[i%5] == answers[i]){
            score[0] += 1;
        }
        //two
        if(i%2 == 0){
            if(answers[i] == 2){
                score[1] += 1;
            }
        }else if(two[Math.floor((i%8)/2)] == answers[i]){
            score[1] += 1;
        }
        //three
        if(three[(Math.floor(i/2))%5] == answers[i]){
            score[2] += 1;
        }
    }
    
    //초기 세팅
    let winner = score[0];
    answer.push(1);
    
    for(i=1; i<3; i++){
        if(score[i] > winner){
            winner = score[i];
            answer = [i+1];
        }else if(score[i] == winner){
            answer.push(i+1);
        }
    }
    
    return answer;
}