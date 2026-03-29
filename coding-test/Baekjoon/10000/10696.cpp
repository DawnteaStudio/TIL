#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int n, t, len, rem, digit;
	string num;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
	    cin >> num >> t;
	    rem = 0;
	    len = num.length();
	    for (int j = 0; j < len; j++) {
	        digit = num[j] - '0';
	        rem = (rem * 10 + digit) % t;
	    }
	    
	    cout << "Case " << i << ": " << rem << '\n';
	}
}
