#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string res, tmp;
    int input, cost;

    cost = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp >> input;
        if (input > cost) {
            res = tmp;
            cost = input;
        }
    }
    cout << res;
}