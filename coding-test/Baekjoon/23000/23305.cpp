#include <iostream>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, total;
    cin >> n;
    total = n;
    map<int, int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (a.find(x) == a.end())
            a[x] = 1;
        else
            a[x]++;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (a[x] > 0)
        {
            a[x]--;
            total--;
        }
    }
    cout << total;
}
