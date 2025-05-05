#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string input;
    cin >> input;
    int a = 0, b = 0;

    int cnt = 0;
    int len = input.length();
    for (int i = 0; i < len; i++) {
        if (input[i] == 'A')
            a++;
        else
            b++;
        if (a == 21 || b == 21) {
            cout << a << "-" << b << '\n';
            if (a == 21)
                cnt++;
            a = b = 0;
        }
    }
    if (cnt == 2)
        cout << "A";
    else
        cout << "B";
}
