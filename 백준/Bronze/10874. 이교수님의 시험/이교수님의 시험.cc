#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int n, s;
	cin >> n;
	
	int tmp;
	for (int i = 1; i <= n; i++) {
	    tmp = 0;
	    for (int j = 1; j <= 10; j++) {
	        cin >> s;
	        if (((j - 1) % 5) + 1 == s)
	            tmp++;
	    }
	    if (tmp == 10)
	        cout << i << '\n';
	}
}