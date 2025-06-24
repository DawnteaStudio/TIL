#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m, k;
    cin >> n >> m >> k;
    cout << (m / n) * k;
}