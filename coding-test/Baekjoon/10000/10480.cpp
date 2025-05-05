#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
    fast;
    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num == 0 || num % 2 == 0)
            cout << num << " is even\n";
        else
            cout << num << " is odd\n";
    }
}
