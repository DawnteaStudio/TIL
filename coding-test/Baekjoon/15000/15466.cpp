#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, a, b, input, inter, uni;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        inter = 0;
        uni = 0;
        vector<bool> visited(10, false);
        for (int j = 0; j < a + b; j++) {
            cin >> input;
            if (visited[input] == false) {
                uni++;
                visited[input] = true;
            }
            else
                inter++;
        }
        if (inter * 2 > uni)
            cout << 1;
        else
            cout << 0;
        cout << '\n';
    }
}
