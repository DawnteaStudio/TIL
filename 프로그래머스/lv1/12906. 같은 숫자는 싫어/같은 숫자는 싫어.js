function solution(arr)
{
    let testCase = arr[0];    
    var answer = [testCase];
    
    for(i=0;i<arr.length;i++){
        if(arr[i] !== testCase){
            answer.push(arr[i]);
            testCase = arr[i];
        }
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    console.log(answer);
    
    return answer;
}