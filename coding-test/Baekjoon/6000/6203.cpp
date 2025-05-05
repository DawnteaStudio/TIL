#include <iostream>
#include <vector>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

double get_dist(int x1, int y1, int x2, int y2)
{
    double res;

    res = sqrt(static_cast<double>(pow(x1 - x2, 2)) + static_cast<double>(pow(y1 - y2, 2)));
    return res;
}

int main()
{
    fast;
    int n, x, y, cow = 1;
    cin >> n;
    vector<pair<int, int> > vec(n + 1);
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        vec[i] = make_pair(x, y);
    }
    int cnt = 1, candidate;
    x = vec[1].first;
    y = vec[1].second;
    while (cnt != n) {
        double dist = 0, tmp;
        for (int i = 1; i <= n; i++) {
            if (i == cow)
                continue;
            if (visited[i])
                continue;
            tmp = get_dist(x, y, vec[i].first, vec[i].second);
            if (dist == 0 || dist > tmp) {
                dist = tmp;
                candidate = i;
            }
        }
        visited[candidate] = true;
        cnt++;
        do {
            cow++;
            if (cow > n)
                cow = 1;
        } while (visited[cow] == true);
        x = vec[cow].first;
        y = vec[cow].second;
    }
    cout << cow;
}
