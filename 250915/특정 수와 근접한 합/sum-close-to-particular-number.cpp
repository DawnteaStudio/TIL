#include <iostream>
#include <cmath>

using namespace std;

int N, S, ans = 10001;
int arr[100];

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Please write your code here.

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int tmp = 0;
            for (int k = 0; k < N; k++) {
                if (k == i || k == j)
                    continue;
                tmp += arr[k];
            }
            if (abs(tmp - S) < ans)
                ans = abs(tmp - S);
        }
    }
    cout << ans;
    return 0;
}