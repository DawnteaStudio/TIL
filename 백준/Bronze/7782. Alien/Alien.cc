// Alien
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
    cin >> n;
	int b1, b2;
    cin >> b1 >> b2;
	int l[2], h[2];
	for (int i=0; i<n; i++) {
		cin >> l[0] >> l[1] >> h[0] >> h[1];

		if (b1 >= l[0] && b1 <= h[0] && b2 >= l[1] && b2 <= h[1]) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}