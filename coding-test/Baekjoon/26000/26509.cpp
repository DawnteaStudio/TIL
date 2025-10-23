#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;
    bool flag;

    vector<int> a(3);
    vector<int> b(3);
    for (int i = 0; i < n; i++) {
        flag = true;
        for (int j = 0; j < 3; j++)
            cin >> a[j];
        for (int j = 0; j < 3; j++)
            cin >> b[j];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int j = 0; j < 3; j++) {
            if (a[j] != b[j]) {
                cout << "NO";
                flag = false;
                break;
            }
        }
        if (flag) {
            if (a[2] * a[2] != a[0] * a[0] + a[1] * a[1])
                cout << "NO";
            else
                cout << "YES";
        }
        cout << '\n';
    }
}
