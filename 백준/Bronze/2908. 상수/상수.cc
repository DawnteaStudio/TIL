#include <iostream>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	string a, b;
	cin >> a >> b;

	string res_a = a, res_b = b;
	reverse(res_a.begin(), res_a.end());
	reverse(res_b.begin(), res_b.end());

	for (int i = 2; i >= 0; i--) {
		if (a[i] > b[i]) {
			cout << res_a;
			break;
		}
		else if (a[i] < b[i]) {
			cout << res_b;
			break;
		}
	}
}