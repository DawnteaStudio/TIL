#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    long long a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);

    int diff = b - a - 1;
    if (diff < 0)
        diff++;
    cout << diff << '\n';
    for (long long i = a + 1; i < b; i++)
        cout << i << " ";
}
