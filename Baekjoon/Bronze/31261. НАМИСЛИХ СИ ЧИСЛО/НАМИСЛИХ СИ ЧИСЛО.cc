#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    b += a;
    b *= a;
    b += a;
    b *= a;
    cout << b;
}