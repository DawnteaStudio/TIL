#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string n;
    cin >> n;
    
    if (n[0] == '5' && n[1] == '5' && n[2] == '5')
        cout << "YES";
    else
        cout << "NO";
}
