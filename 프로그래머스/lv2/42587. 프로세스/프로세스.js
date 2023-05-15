function solution(priorities, location) {
    var answer = 0;
    let sortPors = [...priorities].sort((a,b) => b-a);
    let locationPop = false;

    while(locationPop == false){
        if(sortPors[0] == priorities[0]){
            priorities.shift();
            sortPors.shift();
            answer++;
            if(location == 0){
                return answer;
            }
        }else{
            let shift = priorities.shift()
            priorities.push(shift);
        }
        
        location > 0 ? location-- : location = priorities.length-1;
    }
    
    
    return answer;
}