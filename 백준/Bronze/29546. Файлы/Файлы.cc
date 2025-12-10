#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	cin >> n;
	vector<string> vec(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> vec[i];
	
	int t, a, b;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		for (int j = a; j <= b; j++)
			cout << vec[j] << '\n';
	}
}
