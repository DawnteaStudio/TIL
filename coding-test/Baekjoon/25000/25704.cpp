#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int coupon, price, res;
    cin >> coupon >> price;
    if (coupon >= 20)
    {
        if (price / 100 * 25 > 2000)
            res = price / 100 * 75;
        else
            res = price - 2000;
    }
    else if (coupon >= 15)
    {
        if (price / 100 * 10 > 2000)
            res = price / 100 * 90;
        else
            res = price - 2000;
    }
    else if (coupon >= 10)
    {
        if (price / 100 * 10 > 500)
            res = price / 100 * 90;
        else
            res = price - 500;
    }
    else if (coupon >= 5)
        res = price - 500;
    else
        res = price;

    if (res < 0)
        res = 0;
    cout << res;
}