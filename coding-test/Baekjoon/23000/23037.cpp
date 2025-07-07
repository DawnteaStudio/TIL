#include <iostream>
#include <string>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string input;
    int res = 0;
    int tmp;
    cin >> input;
    for (int i = 0; i < 5; i++)
    {
        tmp = input[i] - '0';
        res += pow(tmp, 5);
    }
    cout << res;
}