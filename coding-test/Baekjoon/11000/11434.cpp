#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        long long N, W, E;
        cin >> N >> W >> E;

        long long ans = 0;

        for (long long i = 0; i < N; i++) {
            long long w1, w2, e1, e2;
            cin >> w1 >> w2 >> e1 >> e2;

            long long choice1 = W * w1 + E * e1;
            long long choice2 = W * w2 + E * e2;

            ans += max(choice1, choice2);
        }

        cout << "Data Set " << tc << ":\n";
        cout << ans << "\n\n";
    }
}
