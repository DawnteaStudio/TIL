function solution(numbers) {
    var answer = 0;
    let numArr = numbers.split('');
    let caseSet = new Set();
    let testArr = [];
        
    function isPrime(n) {
	    if (n < 2) return false;
	    for (let i = 2; i <= Math.sqrt(n); i++) {
		    if (n % i === 0) return false;
	    }
	    return true;
    }
    
    //ref : https://velog.io/@devjade/JavaScript%EB%A1%9C-%EC%88%9C%EC%97%B4%EA%B3%BC-%EC%A1%B0%ED%95%A9-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B5%AC%ED%98%84%ED%95%98%EA%B8%B0
  function combinate(arr, num) {
    if (num === 1) return arr.map(v => v.toString()); // 각 요소를 문자열로 변환하여 반환

    let result = [];

    arr.forEach((fixed, index, origin) => {
      const rest = origin.slice(index + 1);
      const combinations = combinate(rest, num - 1);
      const attached = combinations.map(v => fixed.toString() + v); // 요소를 합쳐서 문자열로 생성
      result.push(...attached);
    });

    return result;
  }
    
    for (let i = 1; i <= numbers.length; i++) {
    const combinationsResult = combinate(numArr, i); // combinate 함수의 반환값 활용
    testArr.push(...combinationsResult); // testArr 대신 combinationsResult 활용
  }
    
    function permutate(arr){
        function tree(i, arr){
            if(i == arr.length){
                return caseSet.add(Number([...arr].join('')));
            }            
            for(let j=i;j<arr.length;j++){
                [arr[i], arr[j]] = [arr[j],arr[i]];
                tree(i+1, arr);
                [arr[i], arr[j]] = [arr[j],arr[i]];
            }
        }
        tree(0, arr);
    }
    
    for(i of testArr){
        permutate(i.split(''));
    }
    
    for(i of caseSet){
        if(isPrime(i)){
            answer++;
        }
    }
    
    return answer;
}
