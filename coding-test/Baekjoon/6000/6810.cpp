#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, res = 0;
    string str = "9780921418";
    for (int i = 0; i < 3; i++)
    {
        cin >> n;
        str += n + '0';
    }
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0)
            res += str[i] - '0';
        else
            res += 3 * (str[i] - '0');
    }
    cout << "The 1-3-sum is " << res;
}
