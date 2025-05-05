#include <iostream>
#include <vector>
#include <algorithm>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m, tmp, res = 0;
    cin >> n >> m;
    int start_i = 0, end_i = n - 1;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);   
    }
    sort(v.begin(), v.end());
    while (start_i < end_i)
    {
        tmp = v[start_i] + v[end_i];
        if (tmp == m)
        {
            res++;
            start_i++;
            end_i--;
        }
        else if (tmp < m)
            start_i++;
        else
            end_i--;
    }
    cout << res;
}