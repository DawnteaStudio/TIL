#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(void)
{
    fast;
    int cnt, len;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> len;
        vector<string> v1(len);
        vector<string> v2(len);
        vector<int> order;
        vector<string> p(len);
        for (int j = 0; j < len; j++)
            cin >> v1[j];
        for (int j = 0; j < len; j++)
            cin >> v2[j];
        for (int j = 0; j < len; j++)
        {
            for (int k = 0; k < len; k++)
            {
                if (v2[j] == v1[k])
                {
                    order.push_back(k);
                    break;
                }
            }
        }
        for (int j = 0; j < len; j++)
            cin >> p[order[j]];
        for (int j = 0; j < len; j++)
            cout << p[j] << ' ';
        cout << '\n';
    }
}