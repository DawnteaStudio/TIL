#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, tmp, input, len;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        tmp = input;
        len = 1;
        while (tmp) {
            tmp /= 10;
            len *= 10;
        }
        if (input == (input * input) % len)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}