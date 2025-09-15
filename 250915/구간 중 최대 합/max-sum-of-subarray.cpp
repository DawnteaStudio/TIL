#include <iostream>

using namespace std;

int n, k, ans;
int arr[100];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    for (int i = 0; i < n - k; i++) {
        int tmp = 0;
        for (int j = 0; j < k; j++) {
            tmp += arr[i + j];
        }
        if (ans < tmp)
            ans = tmp;
    }
    cout << ans;
    return 0;
}