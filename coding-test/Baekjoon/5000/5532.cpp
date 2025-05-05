#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    double L, A, B, C, D, total;
    cin >> L >> A >> B >> C >> D;
    if (ceil(A/C) > ceil(B/D))
        total = ceil(A/C);
    else
        total = ceil(B/D);
    cout << L - total << '\n';
}
