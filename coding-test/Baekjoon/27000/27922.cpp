#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(int &a, int &b)
{
    return a > b;
}

int main()
{
    fast;
    int n, k;
    cin >> n >> k;

    int a, b, c;
    vector<int> one, two, thr;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        one.push_back(a + b);
        two.push_back(a + c);
        thr.push_back(b + c);
    }
    sort(one.begin(), one.end(), cmp);
    sort(two.begin(), two.end(), cmp);
    sort(thr.begin(), thr.end(), cmp);

    int res1 = 0, res2 = 0, res3 = 0;
    for (int i = 0; i < k; i++) {
        res1 += one[i];
        res2 += two[i];
        res3 += thr[i];
    }

    cout << max(res1, max(res2, res3));
}
