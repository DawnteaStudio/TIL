#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A = 0, B = 0, C = 0;

    if (N % 10 != 0)
        cout << -1;
    else
    {
        A = N / 300;
        N %= 300;
        B = N / 60;
        N %= 60;
        C = N / 10;
        cout << A << " " << B << " " << C;
    }
}
