#include <iostream>

using namespace std;

int main() {
    int arr[5];
    int num[5];

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        num[i] = arr[i];
    }

    int cnt = 0;
    int idx = 0;
    int ans = -1;

    while (ans < 0) {
        int small = num[idx];

        for (int i = 0; i < 5; i++) {
            cnt = 0;
            if (small > num[i]) {
                idx = i;
                small = num[i];
            }
        }
        for (int j = 0; j < 5; j++) {
            if (small % arr[j] == 0)
                cnt++;
        }
        if (cnt >= 3) {
            if (ans < 0 || ans > small)
                ans = small;
        }
        num[idx] += arr[idx];
    }
    cout << ans;
}