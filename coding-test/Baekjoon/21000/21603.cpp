#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, k; cin >> n >> k;

    int fk = k % 10, f2k = (fk * 2) % 10;
    vector<int> result;
    for (int x=1; x<=n; x++) {
        int fx = x % 10;
        if (fx != fk && fx != f2k) result.push_back(x);
    }

    int size = (int)result.size();
    cout << size << '\n';
    if (size == 0) return (0);
    for (int i=0; i<(int)result.size(); i++) cout << result[i] << ' ';
    return (0);
}