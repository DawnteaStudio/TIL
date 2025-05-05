#include <iostream>
#include <map>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    
    int n, max_num = 0;
    string str, res;
    cin >> n;
    map<string, int> m;
    
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (m.find(str) == m.end())
            m.insert({str, 1});
        else
            m.find(str)->second++;
    }
    for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++)
    {
        if (iter->second > max_num)
        {
            res = iter->first;
            max_num = iter->second;
        }
    }
    cout << res;
}