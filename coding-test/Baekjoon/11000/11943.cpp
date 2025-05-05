#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int A, B, C, D, res;
    cin >> A >> B >> C >> D;
    res = A + D < B + C ? (A + D) : (B + C);
    cout << res;
}
