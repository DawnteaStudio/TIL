#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;
    string number;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        if ((number[number.size() - 1] - '0') % 2 == 0)
            cout << "even\n";
        else
            cout << "odd\n";
    }
    return (0);
}