#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int cnt_divisors(int number)
{
    int res = 0;
    for (int i = 1; i <= number / i; i++) {
        if (number % i == 0) {
            if (number / i != i) res += 2;
            else res++;
        }
    }
    return res;
}

int main()
{
    fast;
    int c, n;
    cin >> c;
    for (int i=0; i<c; i++) {
        cin >> n;
        cout << n << " " << cnt_divisors(n) << '\n';
    }
    return (0);
}