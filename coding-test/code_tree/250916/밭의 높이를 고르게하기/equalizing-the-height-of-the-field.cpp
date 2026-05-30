#include <iostream>
#include <cmath>
using namespace std;

int N, H, T, res = 99999999;
int arr[100];

int main() {
    cin >> N >> H >> T;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    for (int i = 0; i <= N - T; i++) {
        int tmp = 0;
        for (int j = i; j < i + T; j++) {
            tmp += abs(H - arr[j]);
        }
        if (res > tmp)
            res = tmp;
    }
    cout << res;
    return 0;
}