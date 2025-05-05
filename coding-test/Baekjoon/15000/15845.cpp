#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m;
    int res = 1, cnt = 0;
    cin >> n >> m;

    vector<int> tests(m);
    for (int i = 0; i < m; i++)
        cin >> tests[i];
    for (int i = 1; i <= n; i++)
    {
        int input, tmp = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> input;
            if (input == tests[j])
                tmp++;
            if (tmp > cnt)
            {
                res = i;
                cnt = tmp;
            }
        }
    }
    cout << res;
}
