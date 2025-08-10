#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n; cin >> n;
	string s1, s2;
	for (int i=1; i<=n; i++) {
		cin >> s1 >> s2;
		cout << "Case " << i << ": " << s2 << ", " << s1 << '\n';
	}
	return (0);
}