#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, res = 0;
    string str;
    cin >> str >> n;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp == str)
            res++;
    }
    cout << res;
}
