#include <iostream>
#include <vector>
#include <string>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m;
    cin >> n >> m;
    string input;
    map<string, int> names;
    map<string, int> res;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        names[input] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> input;
        if (names.find(input) != names.end())
            res[input] = 1;
    }
    cout << res.size() << '\n';
    for (map<string, int>::iterator iter = res.begin(); iter != res.end(); iter++)
        cout << (*iter).first << '\n';
}