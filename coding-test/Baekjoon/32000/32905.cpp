#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool comp(pair<int, char> &a, pair<int, char> &b)
{
    return a.first < b.first;
}

int main()
{
    fast;
    int n, m;
    char c;
    cin >> n >> m;
    bool flag;
    for (int i = 0; i < n; i++)
    {
        flag = true;
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            if (c == 'A')
            {
                if (flag == false)
                {
                    cout << "No";
                    return 0;
                }
                flag = false;
            }
        }
        if (flag)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}