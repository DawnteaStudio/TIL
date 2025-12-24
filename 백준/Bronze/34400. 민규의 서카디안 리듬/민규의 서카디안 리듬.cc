// 복붙용
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int tmp;
        cin >> tmp;

        tmp %= 25;
        if (tmp < 17)
            cout << "ONLINE\n";
        else
            cout << "OFFLINE\n";
    }

    return (0);
}