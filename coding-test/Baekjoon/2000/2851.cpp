#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int mush, tmp = 0, res = 0;

    while(1)
    {
        cin >> mush;
        if(cin.eof())
            break;
        tmp += mush;
        if (tmp < 100)
            res = tmp;
        else
        {
            if (100 - res >= tmp - 100)
                res = tmp;
            break;
        }
    }
    cout << res;
}