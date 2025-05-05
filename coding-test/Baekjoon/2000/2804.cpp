#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string a, b;
    bool flag = false;
    cin >> a >> b;

    int len_a = a.length();
    int len_b = b.length();

    int i = 0, j = 0;
    for (; i < len_a; i++) {
        j = 0;
        for (; j < len_b; j++) {
            if (a[i] == b[j]) {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    for (int p = 0; p < len_b; p++) {
        for (int q = 0; q < len_a; q++) {
            if (q == i)
                cout << b[p];
            else if (p == j)
                cout << a[q];
            else
                cout << ".";
        }
        cout << '\n';
    }
}