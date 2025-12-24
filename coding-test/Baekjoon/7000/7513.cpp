// 준살 프로그래밍 대회
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t; cin >> t;
	int m, n;
	for (int i=0; i<t; i++) {
		cin >> m;
		string words[m];
		for (int j=0; j<m; j++) cin >> words[j];

		cin >> n;
		string passwd[n];
		int cnt, idx;
		for (int j=0; j<n; j++) {
			cin >> cnt;
			for (int h=0; h<cnt; h++) {
				cin >> idx;
				passwd[j] += words[idx];
			}
		}

		cout << "Scenario #" << i + 1 << ":\n";
		for (int j=0; j<n; j++) cout << passwd[j] << '\n';
		cout << '\n';
	}
	return (0);
}