#include <iostream>
#include <string>
#include <map>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int mini_atoi(string str)
{
    int res = 0;
    for (int i = 0; i < str.length(); i++)
        res = res * 10 + (str[i] - '0');
    return (res);
}

int main()
{
    fast;
    string pocketmon;
    map<string, int> pocket;
    map<int, string> pocket2;
    int id, pks, cases;
    cin >> pks >> cases;
    for (int i = 1; i <= pks; i++)
    {
        cin >> pocketmon;
        pocket.insert({pocketmon, i});
        pocket2.insert({i, pocketmon});
    }
    for (int i = 0; i < cases; i++)
    {
        cin >> pocketmon;
        if (pocketmon[0] >= '1' && pocketmon[0] <= '9')
        {
            id = mini_atoi(pocketmon);
            if (pocket2.find(id) != pocket2.end())
                cout << pocket2.find(id)->second;
        }
        else
        {
            if (pocket.find(pocketmon) != pocket.end())
                cout << pocket.find(pocketmon)->second;
        }
        cout << '\n';
    }
}
