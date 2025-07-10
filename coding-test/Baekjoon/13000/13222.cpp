#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, w, h; cin >> n >> w >> h;

	int len, diagonal = (int)sqrt(w * w + h * h);
	for (int i=0; i<n; i++) {
		cin >> len;
		if (len <= diagonal) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
