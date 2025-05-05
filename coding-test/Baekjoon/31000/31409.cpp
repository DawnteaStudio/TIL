#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, cnt = 0, input;
    vector<int> v;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> input;
        if (input == i) {
            cnt++;
            if (i == n)
                v.push_back(i - 1);
            else
                v.push_back(i + 1);
        }
        else
            v.push_back(input);
    }
    cout << cnt << '\n';
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
}

