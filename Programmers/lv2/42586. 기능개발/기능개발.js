function solution(progresses, speeds) {
    const remainDays = progresses.map((progress, index) => Math.ceil((100 - progress) / speeds[index])); 
    const answer = [];
    
    let releaseDay = remainDays[0];
    let count = 1;
    
    for (let i = 1; i < remainDays.length; i++) {
        if (remainDays[i] <= releaseDay) {
            count++;
        } else {
            answer.push(count);
            count = 1;
            releaseDay = remainDays[i];
        }
    }
    answer.push(count);
    
    return answer;
}