#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    long long a, b;

    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) break ;

        long long tmp = a * 2 - b;
        tmp = min(tmp, b * 2 - a);
        tmp = min((a + b) / 2, tmp);
        cout << tmp << '\n';
    }
    return (0);
}