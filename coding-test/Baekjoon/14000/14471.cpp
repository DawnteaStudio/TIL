#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, m, tmp = 0, cost = 0;
    cin >> n >> m;

    int win, blank;
    for (int i = 0; i < m; i++)
    {
        cin >> win >> blank;
        if (blank > n)
        {
            if (blank - n > tmp)
                tmp = blank - n;
            cost += blank - n;
        }
    }
    cout << cost - tmp;
}
