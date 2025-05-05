#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, res = 1;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int tmp = 0;
        for (int j = i; i < n; j++)
        {
            tmp += j;
            if (tmp > n)
                break;
            else if (tmp == n)
            {
                res++;
                break;
            }
        }
    }
    cout << res;
}
