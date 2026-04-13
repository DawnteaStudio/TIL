#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    long long c[3], m[3];

    for (int i = 0; i < 3; i++) {
        cin >> c[i] >> m[i];
    }

    for (int i = 0; i < 100; i++) {
        int from = i % 3;
        int to = (i + 1) % 3;

        long long move = min(m[from], c[to] - m[to]);
        m[from] -= move;
        m[to] += move;
    }

    for (int i = 0; i < 3; i++) {
        cout << m[i] << '\n';
    }
}
