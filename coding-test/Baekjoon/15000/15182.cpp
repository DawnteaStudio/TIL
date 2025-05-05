#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, brokeByte, brokeBit, cnt = 0;
    cin >> n;
    int arr[n + 1][8];
    int check[2] = {0,};
    bool even = false;

    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 0; j < 8; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                cnt++;
        }
        if (cnt % 2 == 0)
            check[0]++;
        else
            check[1]++;
    }

    for (int i = 0; i < 8; i++)
        cin >> arr[n][i];
    even = check[0] > check[1];
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 0; j < 8; j++)
        {
            if (arr[i][j] == 1)
                cnt++;
        }
        if (even)
        {
            if (cnt % 2 != 0)
            {
                brokeByte = i + 1;
                break;
            }
        }
        else
        {
            if (cnt % 2 == 0)
            {
                brokeByte = i + 1;
                break;
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        cnt = 0;
        for (int j = 0; j <= n; j++)
        {
            if (arr[j][i] == 1)
                cnt++;
        }
        if (even)
        {
            if (cnt % 2 != 0)
            {
                brokeBit = i + 1;
                break;
            }
        }
        else
        {
            if (cnt % 2 == 0)
            {
                brokeBit = i + 1;
                break;
            }
        }
    }

    if (even)
        cout << "Even\n";
    else
        cout << "Odd\n";
    cout << "Byte " << brokeByte << " is broken\n";
    cout << "Bit " << brokeBit << " is broken\n";
}
