#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int a1, a2, b1, b2;
    int gunnar= 0, emma = 0;

    cin >> a1 >> b1 >> a2 >> b2;
    gunnar += a1 + b1 + a2 + b2;
    cin >> a1 >> b1 >> a2 >> b2;
    emma += a1 + b1 + a2 + b2;
    if (gunnar > emma)
        cout << "Gunnar";
    else if (gunnar < emma)
        cout << "Emma";
    else
        cout << "Tie";
}