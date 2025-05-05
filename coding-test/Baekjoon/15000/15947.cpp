#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;

    string arr[] = {"sukhwan", "baby", "sukhwan", "tururu", "turu", "very", "cute", "tururu", "turu", "in", "bed", "tururu", "turu", "baby"};
    string res = arr[n % 14];
    int cnt = n / 14;
    if (res[0] == 't')
    {
        if (cnt <= 2)
        {
            for (int i = 0; i < cnt; i++)
                res += "ru";
        }
        else if (cnt == 3 && res.length() == 4)
            res += "rururu";
        else
        {
            if (res.length() == 6)
                res = "tu+ru*" + to_string(2 + cnt);
            else
                res = "tu+ru*" + to_string(1 + cnt);
        }
    }
    cout << res;
}
