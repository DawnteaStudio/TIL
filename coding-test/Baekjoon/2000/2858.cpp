// 기숙사 바닥
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int R, B; cin >> R >> B;
	for (int i=1; i <= B / i; i++) {
		if (B % i != 0) continue ;
		if (i * 2 + B / i * 2 + 4 == R) {
			cout << B / i + 2 << " " << i + 2;
			break ;
		}
	}
	return (0);
}