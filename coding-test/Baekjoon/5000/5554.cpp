#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int a, b, c, d, min, sec;
    
    cin >> a >> b >> c >> d;
    min = (a + b + c + d) / 60;
    sec = (a + b + c + d) % 60;
    cout << min << '\n' << sec;
}
