#include <iostream>

using namespace std;

int N, M, K;
int student[10000];

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        student[tmp]++;

        if (student[tmp] >= K) {
            cout << tmp;
            return 0;
        }
    }
    cout << -1;
    // Please write your code here.

    return 0;
}