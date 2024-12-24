#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n; cin >> n;
	string str;

	int a, b;
	for (int i=0; i<n; i++) {
		cin >> str >> a >> b;
		for (int j=0; j<(int)str.size(); j++) {
			if (j >= a && j < b) continue ;
			cout << str[j];
		}
		cout << '\n';
	}
}
