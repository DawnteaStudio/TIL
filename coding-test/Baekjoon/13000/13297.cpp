#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 헤더
using namespace std;
// [백준 13297 c++ O] Quick Estimates
// 문제: 
// 접근: 문자열 길이 구하기 -> str.size() 이용
// 시간복잡도: O(n) = 100 
// 풀이: 
string a;
int n;
 
int main()
{
    ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
    cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
    
    cin >> n;
    while (n--) {
        cin >> a;
        cout << a.size() << '\n';
    }
    return 0;
}