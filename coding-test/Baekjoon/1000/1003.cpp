#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

vector<pair<int, int>> v(41);
vector<pair<int, int>> res;
int main()
{
    int T, N;
    cin >> T;
    v[0] = {1, 0};
    v[1] = {0, 1};

    for (int i = 2; i <= 40; i++)
        v[i] = {v[i - 1].first + v[i - 2].first, v[i - 1].second + v[i - 2].second};
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        res.push_back(v[N]);
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i].first << ' ' << res[i].second << '\n';
}
