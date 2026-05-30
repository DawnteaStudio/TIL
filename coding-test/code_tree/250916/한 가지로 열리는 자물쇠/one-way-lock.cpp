#include <iostream>
#include <cmath>
using namespace std;

int N;
int a, b, c;

int main() {
    cin >> N;
    cin >> a >> b >> c;

    int res = 0;
    // Please write your code here.
    for (int i = 1; i <= N; i++) {
        if (abs(i - a) <= 2) {
            res += N * N;
            continue;
        }
        for (int j = 1; j <= N; j++) {
            if (abs(j - b) <= 2) {
                res += N;
                continue;
            }
            for (int p = 1; p <= N; p++) {
                if (abs(p - c) <= 2)
                    res++;
            }
        }
    }
    cout << res;
    return 0;
}