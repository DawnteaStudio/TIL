#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    vector<long long> v(10000, -1);
    int index = 1;
    v[0] = 1;
    v[1] = 1;

    string tmp;
    while (cin >> n)
    {
        tmp = " ";
        if (n < 10)
            tmp = "    ";
        else if (n < 100)
            tmp = "   ";
        else if (n < 1000)
            tmp = "  ";

        if (v[n] != -1)
            cout << tmp << n << " -> " << (v[n] % 10) << '\n';
        else
        {
            long long cost = v[index];
            int i = index + 1;
            for (; i <= n; i++)
            {
                cost *= i;
                while (cost % 10 == 0)
                    cost /= 10;
                cost %= 10000000;
                v[i] = cost;
            }
            index = n;
            cout << tmp << n << " -> " << (v[n] % 10) << '\n';
        }
    }
}