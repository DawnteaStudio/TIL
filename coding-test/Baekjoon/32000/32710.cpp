#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n;
    bool flag = false;
    cin >> n;
    if (n == 1)
        flag = true;
    else
    {
        for (int i = 2; i <= 9; i++)
        {
            if (n % i == 0 && n / i <= 9)
            {
                flag = true;
                break;
            }
        }
    }
    if (flag)
        cout << 1;
    else
        cout << 0;
}
