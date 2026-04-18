#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    while (true) {
        int N, M, K;
        cin >> N >> M >> K;

        if (N == 0 && M == 0 && K == 0) break;

        vector<int> pattern(K);
        for (int i = 0; i < K; i++) cin >> pattern[i];

        long long current = N;
        long long sum = N;

        for (int row = 2; row <= M; row++) {
            current += pattern[(row - 2) % K];
            sum += current;
        }

        cout << sum << '\n';
    }
}
