#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int d;
    cin >> d;
    cout << d << '\n';

    for (int i = 0; i < d; ++i) {
        string dish;
        cin >> dish;
        cout << dish << '\n';
    }

    return 0;
}