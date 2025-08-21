#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long f(long long n) {
	long long i=1;
	for (; i*i*i<=n; i++) {
		if (i*i*i == n) return i;
	}
	return i;
}

int main() {
    fast;
	int t; cin >> t;
	long long a, b;
	for (int i=1; i<=t; i++) {
		cin >> a >> b;
		long long tmp = f(a), cnt=0;
		for (; tmp*tmp*tmp<=b; tmp++) cnt++;
		cout << "Case #" << i << ": " << cnt << '\n';
	}
}