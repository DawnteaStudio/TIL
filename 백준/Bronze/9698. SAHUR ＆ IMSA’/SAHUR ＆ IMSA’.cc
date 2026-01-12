#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int t;
	cin >> t;
	int h, m;

	for (int i = 1; i <= t; i++) {
		cin >> h >> m;
		if (m >= 45) 
			cout << "Case #" << i << ": " << h << " " << m - 45 << '\n';
		else {
			m += 15;
			h--;
			if (h < 0)
				h = 23;
			cout << "Case #" << i << ": " << h << " " << m << '\n';
		} 
	}
}