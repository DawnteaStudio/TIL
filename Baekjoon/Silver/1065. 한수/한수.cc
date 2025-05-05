#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N;

int main()
{
    fast;
    cin >> N;
    
    int cnt = 99;
    int a, b, c;
    if (N < 100)
    {
        cout << N;
        return 0;
    }
    if (N == 1000)
        N = 999;
    for (int i = 100; i <= N; i++)
    {
        a = i/100;
        b = (i/10)%10;
        c = i%10;
        if (a - b == b - c)
            cnt++;
    }
    cout << cnt;
}