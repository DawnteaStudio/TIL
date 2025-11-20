// 암호제작
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool isPossibleDivision(string &P, int n) {
	int tmp = 0;
	for (int i=0; i<(int)P.size(); i++) {
		tmp = tmp * 10 + (P[i] - '0');
		if (tmp >= n) tmp %= n;
	}
	return tmp == 0;
}

bool isPrime(int n) {
	for (int i = 2; i <= n / i; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
	fast;
	string P;
	int k; cin >> P >> k;
	int cnt = 0;
	for (int i = 2; i < k; i++) {
		if (!isPrime(i)) continue ;
		cnt++;
		if (isPossibleDivision(P, i)) {
			cout << "BAD " << i;
			return 0;
		}
	}
	cout << "GOOD";
	return (0);
}