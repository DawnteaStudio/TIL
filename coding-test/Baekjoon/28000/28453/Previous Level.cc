#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;

        if (m == 300) {
            cout << 1 << " ";
        } else if (m >= 275) {
            cout << 2 << " ";
        } else if (m >= 250) {
            cout << 3 << " ";
        } else {
            cout << 4 << " ";
        }
    }

    return 0;
}