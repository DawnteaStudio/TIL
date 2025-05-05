#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;

int main()
{
    fast;
    ll num, cut = 2;
    bool swap = false;
    cin >> num;
    while (num > 2)
    {
        if (num <= cut * 2)
        {
            num -= cut;
            if (swap)
                swap = false;
            else
                swap = true;
            cut = 2;
        }
        else
            cut *= 2;
    }
    num -= 1;
    if (swap)
        num ^= 1;
    cout << num;
}