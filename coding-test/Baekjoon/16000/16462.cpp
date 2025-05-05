#include <iostream>
#include <string>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, res = 0;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        int tmp = 0;
        if (str.length() >= 3)
            res += 100;
        else {
            for (int j = 0; j < (int)str.length(); j++) {
                if (str[j] == '0' || str[j] == '6')
                    tmp = tmp * 10 + 9;
                else
                    tmp = tmp * 10 + str[j] - '0';
            }
            res += tmp;
        }
    }
    cout << round(res / static_cast<double>(n));
}