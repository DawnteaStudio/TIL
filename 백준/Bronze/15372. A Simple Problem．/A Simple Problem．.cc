#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int n;
	cin >> n;

	long long tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		cout << tmp * tmp << '\n';
	}
}