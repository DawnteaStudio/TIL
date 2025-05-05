#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, p, t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> t;
        cout << p - t / 7 + t / 4 << '\n';
    }
}

