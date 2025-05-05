#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int res[16], size = 16;
    string num1, num2;
    cin >> num1 >> num2;
    for (int i = 0; i < 16; i++)
    {
        if (i % 2 == 0)
            res[i] = num1[i / 2] - '0';
        else
            res[i] = num2[i / 2] - '0';
    }
    while (size != 2)
    {
        for (int i = 0; i < size - 1; i++)
            res[i] = (res[i] + res[i + 1]) % 10;
        size--;
    }
    cout << res[0] << res[1];
}
