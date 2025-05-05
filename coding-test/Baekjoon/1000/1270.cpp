#include <iostream>
#include <vector>
#include <algorithm>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, num, max, tmp_max;
    long long sol, max_sol, tmp;
    cin >> n;
    vector<vector<long long>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> sol;
            v[i].push_back(sol);
        }

        sort(v[i].begin(), v[i].end());
        tmp = v[i][0];
        max = 0;
        tmp_max = 0;
        for (int j = 0; j < num; j++)
        {
            if (v[i][j] == tmp)
                tmp_max++;
            else
            {
                if (tmp_max > max)
                {
                    max_sol = tmp;
                    max = tmp_max;
                }

                tmp = v[i][j];
                tmp_max = 1;
            }
        }
        if (tmp_max > max)
        {
            max = tmp_max;
            max_sol = v[i][num - 1];
        }
        if (max > num / 2)
            cout << max_sol << '\n';
        else
            cout << "SYJKGW\n";
    }
}