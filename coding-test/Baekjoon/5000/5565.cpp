#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int total_price, price;
    cin >> total_price;
    for (int i=0; i<9; i++) {
        cin >> price;
        total_price -= price;
    }
    cout << total_price;
    return (0);
}