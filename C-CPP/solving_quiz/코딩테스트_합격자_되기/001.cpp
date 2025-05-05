// 1. 배열 정렬하기

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    return arr;
}
