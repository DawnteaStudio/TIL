#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;

    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        cout << "Data set: " << a << " " << b << " " << c << '\n';

        for (int j = 0; j < c; j++) {
            if (a > b)
                a /= 2;
            else
                b /= 2;
        }
        int l, s;
        if (a > b)
            l = a;
        else
            l = b;
        s = a + b - l;
        cout << l << " " << s << '\n' << '\n';
    }
}
