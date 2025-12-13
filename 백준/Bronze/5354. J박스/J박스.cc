// J박스
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t; cin >> t;
	int s;
	for (int i=0; i<t; i++) {
		cin >> s;
		for (int j=0; j<s; j++) {
			for (int k=0; k<s; k++) {
				if (j == 0 || j == s - 1) cout << '#';
				else if (k == 0 || k == s - 1) cout << '#';
				else cout << 'J';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return (0);
}