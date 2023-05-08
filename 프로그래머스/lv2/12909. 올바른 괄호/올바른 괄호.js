function solution(s){
    var answer = true;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    let stack = 0;
    
    for(i=0;i<s.length;i++){
        if(s[i] == '('){
            stack++;
        }else{
            if(stack > 0){
                stack--;
            }else{
                answer = false;
                break;
            }
        }
    }
    if(stack > 0) answer = false;
    
    return answer;
}