#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;
    string origin, s_strfry;
    map<char, int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> origin >> s_strfry;
        v.clear();
        for (int j = 0; j < origin.length(); j++)
        {
            if (v.find(origin[j]) != v.end())
                v.find(origin[j])->second++;
            else
                v.insert({origin[j], 1});
        }
        for (int j = 0; j < origin.length(); j++)
        {
            if (v.find(s_strfry[j]) == v.end())
            {
                cout << "Impossible\n";
                break;
            }
            else
            {
                v.find(s_strfry[j])->second--;
                if (v.find(s_strfry[j])->second == 0)
                    v.erase(v.find(s_strfry[j]));
            }
            if (j == origin.length() - 1)
                cout << "Possible\n";
        }
    }

}
