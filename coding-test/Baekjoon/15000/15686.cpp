#include <iostream>
#include <vector>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int res = -1, n, m;
vector<pair<int, int> > house;
vector<pair<int, int> > chicken;

void    solve(vector<int> cost, vector<bool> choose, int cnt, int depth)
{
    int size = choose.size();
    if (size - depth + cnt + 1 < m || depth > size)
        return;
    if (cnt == m)
    {
        int h_size = house.size();
        for (int i = 0; i < h_size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (choose[j] == true)
                {
                    int value = abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second);
                    if (cost[i] == -1 || cost[i] > value)
                        cost[i] = value;
                }
            }
        }
        int tmp = 0;
        for (int i = 0; i < h_size; i++)
        {
            if (cost[i] > 0)
                tmp += cost[i];
        }
        if (tmp < res || res == -1)
            res = tmp;
    }
    else
    {
        choose[depth] = true;
        solve(cost, choose, cnt + 1, depth + 1);
        choose[depth] = false;
        solve(cost, choose, cnt, depth + 1);
    }
}

int main() {
    fast;
    int tmp;
    cin >> n >> m;
    vector<int> cost;
    vector<bool> choose;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            if (tmp == 1)
            {
                house.push_back(make_pair(i, j));
                cost.push_back(-1);
            }
            else if (tmp == 2)
            {
                chicken.push_back(make_pair(i, j));
                choose.push_back(false);
            }
        }
    }
    solve(cost, choose, 0, 0);
    cout << res;
}