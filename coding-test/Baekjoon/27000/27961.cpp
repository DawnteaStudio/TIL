#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    long long n, res = 0;
    long long tmp = 0;
    cin >> n;

    while (n > tmp)
    {
        if (tmp == 0)
            tmp++;
        else
            tmp *= 2;
        res++;
    }
    cout << res;
}
