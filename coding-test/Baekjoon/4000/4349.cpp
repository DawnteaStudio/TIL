#include <iostream>
#include <cmath>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int calc(int a, int b, int c)
{
    return (2 * (a * b + a * c + b * c));
}

int main() {
    fast;
    int n, input, res, tmp, tmp_cri;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        res = input * input * 6;
        int cri = (int)sqrt(input);
        for (int j = 1; j <= cri; j++)
        {
            if (input % j == 0)
            {
                tmp = input / j;
                tmp_cri = (int)sqrt(tmp);
                for (int k = 1; k <= tmp_cri; k++)
                {
                    if (tmp % k == 0)
                    {
                        int calc_res = calc(j, k, tmp / k);
                        if (res > calc_res)
                            res = calc_res;
                    }
                }
            }
        }
        cout << res << '\n';
    }
}

