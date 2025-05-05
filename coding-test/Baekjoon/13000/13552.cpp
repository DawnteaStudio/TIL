#include <iostream>
#include <cmath>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct circle {
    long long x;
    long long y;
    long long z;
};

void    make_circle(vector<circle> &vec, int n)
{
    long long x, y, z;
    circle c;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        c.x = x;
        c.y = y;
        c.z = z;
        vec.push_back(c);
    }
}

void    check(vector<circle> &vec, int n)
{
    long long x, y, z, r, cnt = 0;
    cin >> x >> y >> z >> r;

    long long res;
    for (int i = 0; i < n; i++)
    {
        res = 0;
        res += (x - vec[i].x) * (x - vec[i].x);
        res += (y - vec[i].y) * (y - vec[i].y);
        res += (z - vec[i].z) * (z - vec[i].z);
        if (res <= r * r)
            cnt++;
    }
    cout << cnt << '\n';
}

int main() {
    fast;
    int n, m;
    cin >> n;

    vector<circle> vec;
    make_circle(vec, n);
    cin >> m;
    for (int i = 0; i < m; i++)
        check(vec, n);
}
