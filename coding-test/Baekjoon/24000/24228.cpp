#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    long long n, r;
    cin >> n >> r;
    cout << n + (2 * r) - 1;
}
