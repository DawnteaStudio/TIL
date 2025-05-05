#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int ft_find(vector<pair<string, int> > &v, string &name)
{
    int index = -1;
    int size = v.size();
    for (int i = 0; i < size; i++) {
        if (v[i].first == name) {
            index = i;
            break;
        }
    }
    return index;
}

int main()
{
    fast;
    int w, n, cnt;
    string name, reason, res;
    map<string, int> m = {{"TT", 75}, {"TX", 50}, {"PR", 80}, {"RT", 30}, {"AP", 25}, {"PX", 60}};

    while (true) {
        cin >> w >> n;
        vector<pair<string, int> > v;
        cnt = 0;
        res = "";
        if (w == 0)
            break;
        for (int i = 0; i < n; i++) {
            cin >> name >> reason;
            int index = ft_find(v, name);
            if (index < 0)
                v.push_back(make_pair(name, m[reason]));
            else {
                v[index].second += m[reason];
                if (v[index].second >= 100)
                    cnt++;
            }
        }
        int size = v.size();
        if (cnt == 0)
            cout << "Week " << w << " No phones confiscated\n";
        else { 
            cout << "Week " << w << " ";
            for (int i = 0; i < size; i++) {
                if (v[i].second >= 100)
                    res += v[i].first + ",";
            }
            cout << res.substr(0, res.length() - 1);
            cout << '\n';
        }
    }
}
