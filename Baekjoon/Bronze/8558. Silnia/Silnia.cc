#include <iostream>

using namespace std;

int main()
{
    int n;
    
    cin >> n;
    if (n == 0) cout << 1;
    else if (n <= 2) cout << n;
    else if (n == 3) cout << 6;
    else if (n == 4) cout << 4;
    else if (n >= 5) cout << 0;
    return 0;
}