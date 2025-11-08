#include <iostream>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		int a, b;
		cin >> a >> b;
		for (int j = 0; j < n; j++)
			cin >> a >> b;
		cout << "Material Management " << i << '\n';
		cout << "Classification ---- End!" << '\n';
	}
}
