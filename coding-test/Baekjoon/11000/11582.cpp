#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void    solve(vector<int> &vec, int level, int len)
{
    int size = len / (level / 2);

    for (int i = 0; i < vec.size(); i += size)
        sort(vec.begin() + i, vec.begin() + i + size);
}

int main()
{
    fast;
    int n, level;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    cin >> level;
    for (int i = n; i != level; i /= 2)
        solve(vec, i, n);
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}