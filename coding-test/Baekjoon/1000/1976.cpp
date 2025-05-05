#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, m, tmp;
    bool flag = true;
    cin >> n >> m;
    vector<set<int> > vec(n + 1);

    for (int i = 1; i <= n; i++)
    {
        vec[i].insert(i);
        for (int j = 1; j <= n; j++)
        {
            cin >> tmp;
            if (tmp == 0)
                continue;
            else
                vec[i].insert(j);
        }
    }
    for (int i = 1; i <=n; i++)
    {
        for (set<int>::iterator iter = vec[i].begin(); iter != vec[i].end(); iter++)
        {
            for (set<int>::iterator elem = vec[i].begin(); elem != vec[i].end(); elem++)
                vec[*iter].insert(*elem);
        }
    }

    queue<int> q;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        q.push(tmp);
    }
    int start, end;
    while (q.size() != 1)
    {
        start = q.front();
        q.pop();
        end = q.front();
        if (find(vec[start].begin(), vec[start].end(), end) == vec[start].end())
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";
}