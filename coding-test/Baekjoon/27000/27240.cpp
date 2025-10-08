#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, a, b, s, t;
	cin >> n >> a >> b >> s >> t;
	if (s > t) {
		int tmp = s;
		s = t;
		t = tmp;
	}

	if (t <= a)
		cout << "Outside";
	else if (s >= b)
		cout << "Outside";
	else if (s > a && t < b)
		cout << "City";
	else
		cout << "Full";
}
