#include <iostream>

using namespace std;

int N, K;
int arr[101];
int res;

int main() {
    cin >> N >> K;
    int cnt, pos, sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> cnt >> pos;
        arr[pos] += cnt;
        sum += cnt;
    }

    // Please write your code here.

    for (int i = K; i <= 100 - K; i++) {
        int tmp = 0;
        for (int j = i - K; j <= i + K; j++)
            tmp += arr[j];
        if (res < tmp)
            res = tmp;
    }
    if (K >= 100 - K)
        res = sum;
    cout << res;
    return 0;
}