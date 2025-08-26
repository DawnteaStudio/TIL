#include <iostream>

using namespace std;

int N;
int arr[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int tmp = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0 || arr[i] > arr[i - 1])
            tmp++;
        else
            tmp = 1;
        if (tmp > cnt)
            cnt = tmp;
    }
    cout << cnt;
    return 0;
}