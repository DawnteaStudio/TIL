#include <iostream>

using namespace std;

int N;
int A[100];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Please write your code here.
    int cnt = 0;

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            if (A[j] < A[i])
                continue;
            for (int k = j + 1; k < N; k++) {
                if (A[k] < A[j])
                    continue;
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}