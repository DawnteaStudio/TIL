#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, pos;
    cin >> n;

    string input;
    for (int i = 0; i < n; i++)
    {
        cin >> pos >> input;
        cout << input.substr(0, pos - 1);
        cout << input.substr(pos);
        cout << '\n';
    }
}
