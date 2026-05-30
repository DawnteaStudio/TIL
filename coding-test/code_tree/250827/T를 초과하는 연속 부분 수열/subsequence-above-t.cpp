#include <iostream>

using namespace std;

int n, t;
int arr[1000];

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int tmp = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > t)
            tmp++;
        else
            tmp = 0;
        if (tmp > cnt)
            cnt = tmp;
    }
    cout << cnt;
    return 0;
}