#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;

    int drink, food;
    drink = d > e ? e : d;
    food = a > b ? b : a;
    food = food > c ? c : food;
    cout << drink + food - 50;
}