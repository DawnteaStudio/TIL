#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m, cnt = 0;
    cin >> n >> m;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    
    int pos = n - 1;
    while (m > 0)
    {
        if (m < vec[pos])
            pos--;
        else
        {
            while (m >= vec[pos])
            {
                m -= vec[pos];
                cnt++;
            }
        }
    }
    cout << cnt;
}
