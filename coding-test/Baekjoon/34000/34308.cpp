#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m;

int main() {
	fast;
    
    cin >> n >> m;
    
    int tmp;
    for (int i = 0; i < m; i++) {
        cin >> tmp;

        if (tmp - 1 > n - tmp)
            cout << n;
        else
            cout << 1;
        cout << " ";
    }
}
