#include <iostream>
#include <vector>
using namespace std;

int dat[300001];

int main()
{
    int n, d, h;
    cin >> n >> d;

    int start = 0;
    for (int i = 0; i < n; i++) {
        cin >> h;
        dat[h]++;
        if (h > start)
            start = h;
    }

    long long res = 0;

    for (int i = 0; i < d; i++) {
        if (start == 0)
            break;
        if (dat[start] > 1)
            res += dat[start];
        else
            res++;
        dat[start - 1] += dat[start];
        start--;
    }
    cout << res;
}
