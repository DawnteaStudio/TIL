#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    fast;
    int n, m;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end(), cmp);
    cin >> m;
    vector<int> box(m);

    for (int i = 0; i < m; i++)
    {
        cin >> box[i];
        if (box[i] > vec[0])
        {
            cout << -1;
            return 0;
        }
    }
    sort(box.begin(), box.end(), cmp);
    
    int start = 1, end = m;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < mid; j++)
            {
                if (vec[i] >= box[cnt])
                    cnt++;
                if (cnt == m)
                    break;
            }
            if (cnt == m)
                break;
        }
        if (cnt == m)
            end = mid - 1;
        else
            start = mid + 1;
    }
    cout << start;
}