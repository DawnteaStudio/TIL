#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int tmp, ban, res = 0;
    cin >> ban;
    for (int i = 0; i < 5; i++)
    {
        cin >> tmp;
        if (tmp == ban)
            res++;
    }
    cout << res;
}
