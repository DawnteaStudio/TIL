#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dp[21][21][21];

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return (1);
    if (a > 20 || b > 20 || c > 20)
        return (1048576);
    if (dp[a][b][c] != 0)
        return (dp[a][b][c]);
    if (a < b && b < c)
        dp[a][b][c] = (w(a, b, c - 1) + w(a, b-1, c-1) - w(a, b-1, c));
    else
        dp[a][b][c] = (w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1));
    return dp[a][b][c];
}

int main()
{
    fast;

    int a, b, c;
    cin >> a >> b >> c;
    while (a != -1 || b != -1 || c != -1)
    {
        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        cout << w(a, b, c) << '\n';
        cin >> a >> b >> c;
    }
}