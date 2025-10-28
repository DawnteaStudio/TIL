#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t; cin >> t;
	int n; char c;

	for (int i=0; i<t; i++) {
		cin >> n >> c;
		for (int j=0; j<n; j++)
			cout << c;
		cout << '\n';
	}
	return (0);
}
