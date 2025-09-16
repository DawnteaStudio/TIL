#include <iostream>

using namespace std;

int N, M;
int A[100];
int dat[101];
int res;

int main() {
    cin >> N >> M;
    int tmp;

    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < M; i++) {
        cin >> tmp;
        dat[tmp]++;
    }

    // Please write your code here.
    if (N >= M) {
        int B[101];
        for (int i = 0; i <= N - M; i++) {
            for (int i = 0; i < 101; i++)
                B[i] = dat[i];
            for (int j = i; j < i + M; j++) {
                if (B[A[j]] == 0)
                    break;
                B[A[j]]--;
                if (j == i + M - 1)
                    res++;
            }
        }
    }
    cout << res;
    return 0;
}