#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m;

int main() {
    fast;

    cin >> n >> m;
    if (n >= 6)
        cout << "Love is open door";
    else {
        for (int i = 1; i < n; i++) {
            if (m == 0)
                m++;
            else
                m--;
            cout << m << '\n';
        }
    }
    
}
