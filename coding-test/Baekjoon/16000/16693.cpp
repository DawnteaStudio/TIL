#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a, p1, r, p2;
    double piece = 0, whole = 0;
    cin >> a >> p1 >> r >> p2;

    piece = (double)a / (double)p1;
    whole = M_PI * (double)r * (double)r / (double)p2;
    if (piece > whole)
    {
        cout << "Slice of pizza" << endl;
    }
    else if (piece < whole)
    {
        cout << "Whole pizza" << endl;
    }
}
