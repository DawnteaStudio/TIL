#include <iostream>
#include <vector>
#include <algorithm>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long ft_abs(long long num)
{
    if (num < 0)
        num *= -1;
    return (num);
}

int main()
{
    fast;
    int n;
    long long tmp, res;
    cin >> n;

    int start = 0, end = n - 1;
    int res_start, res_end;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    res = ft_abs(v[start] + v[end]);

    while (start < end)
    {
        tmp = v[start] + v[end];
        if (tmp == 0)
        {
            res_start = start;
            res_end = end;
            break;
        }
        if (ft_abs(tmp) > res)
        {
            if (tmp > 0)
                end--;
            else
                start++;
        }
        else
        {
            res = ft_abs(tmp);
            res_start = start;
            res_end = end;
            if (tmp > 0)
                end--;
            else
                start++;
        }
    }
    cout << v[res_start] << ' ' << v[res_end];
}
