#include <iostream>

using namespace std;

int N, K;
int arr[10001];

int main() {
    cin >> N >> K;
    int largest = 0;
    int pos;
    char c;

    for (int i = 0; i < N; i++) {
        cin >> pos >> c;
        if (c == 'G')
            arr[pos] = 1;
        else
            arr[pos] = 2;
        if (largest < pos)
            largest = pos;
    }

    // Please write your code here.
    int res = 0;
    for (int i = 0; i <= K; i++) {
        res += arr[i];
    }

    int tmp = res;
    for (int i = K + 1; i <= largest; i++) {
        tmp += arr[i];
        tmp -= arr[i - K - 1];
        if (res < tmp)
            res = tmp;
    }
    cout << res;
    return 0;
}