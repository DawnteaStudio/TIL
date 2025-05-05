#include <iostream>
#include <algorithm>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int N1, N2, time;
    string ant1, ant2;
    cin >> N1 >> N2 >> ant1 >> ant2 >> time;

    reverse(ant1.begin(), ant1.end());
    string ans = ant1+ant2;
    string tmp1, tmp2;

    for (int i = 0; i < time; i++)
    {
        for (int j = 0; j < ans.length() - 1; j++)
        {
            if (ant1.find(ans[j]) != -1 && ant2.find(ans[j + 1]) != -1)
            {
                tmp1 = ans.substr(0, j) + ans[j + 1];
                if (j + 1 == ans.length() - 1)
                    tmp2 = ans[j];
                else
                    tmp2 = ans[j] + ans.substr(j + 2);
                ans = tmp1 + tmp2;
                j++;
            }
        }
    }
    cout << ans;
}