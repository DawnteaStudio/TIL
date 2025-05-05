#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m;
    cin >> n >> m;

    vector<pair<string, string> > vec(n);
    int tmp;
    string melody, name, ch;
    for (int i = 0; i < n; i++)
    {
        melody = "";
        cin >> tmp;
        cin >> name;
        for (int j = 0; j < 7; j++)
        {
            cin >> ch;
            if (j < 3)
                melody += ch;
        }
        vec[i] = make_pair(name, melody);
    }
    int cnt;
    for (int i = 0; i < m; i++)
    {
        cnt = 0;
        melody = "";
        for (int j = 0; j < 3; j++)
        {
            cin >> ch;
            melody += ch;
        }
        for (int j = 0; j < n; j++)
        {
            if (vec[j].second == melody)
            {
                cnt++;
                name = vec[j].first;
            }
        }
        if (cnt == 1)
            cout << name << '\n';
        else if (cnt == 0)
            cout << "!\n";
        else
            cout << "?\n";
    }
}
