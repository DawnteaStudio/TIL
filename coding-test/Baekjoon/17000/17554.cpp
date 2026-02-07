#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;

    int n, k;
	cin >> n >> k;
	int res = 0, tmp = 0, c, next;
	vector<int> vec(n + 1, 1);
	
	for (int i = 0; i < k; i++) {
		cin >> c;
		next = c;
		for (;next <= n; next += c) {
			if (vec[next]) {
				vec[next]--;
				tmp++;
			}
			else {
				vec[next]++;
				tmp--;
			}
		}
		if (tmp > res)
			res = tmp;
	}
	cout << res;
}
