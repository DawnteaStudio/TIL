#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int votes[101];

int main()
{
    fast;
    int N, M, num;
    bool done;
    cin >> N >> M;

    vector<pair<int, int>> v(N);
    vector<int> res;

    for (int i = 0; i < M; i++)
    {
        cin >> num;
        votes[num]++;
        done = false;
        for (int j = 0; j < N; j++)
        {
            if (v[j].first == 0)
            {
                v[j].first = num;
                v[j].second = i;
                done = true;
                break;
            }
            else if (v[j].first == num)
            {
                done = true;
                break;
            }
        }
        if (!done)
        {
            int index = 0;
            for (int j = 1; j < N; j++)
            {
                if (votes[v[index].first] > votes[v[j].first])
                    index = j;
                else if (votes[v[index].first] == votes[v[j].first])
                {
                    if (v[index].second > v[j].second)
                        index = j;
                }
            }
            votes[v[index].first] = 0;
            v[index].first = num;
            v[index].second = i;
        }
    }
    for (int i = 0; i < N; i++)
        res.push_back(v[i].first);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] != 0)
            cout << res[i] << ' ';
    }
}