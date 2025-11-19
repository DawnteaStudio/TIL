#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int K; cin >> K;
	int n, k;
	for (int i=0; i<K; i++) {
		cin >> n >> k;
		string sample; cin >> sample;
		string ancestors[n];
		int cnt = 0;
		for (int j=0; j<n; j++) cin >> ancestors[j];
		for (int j=0; j<k; j++) {
			bool check = true;
			for (int h=0; h<n; h++) {
				if (ancestors[h][j] == sample[j]) {
					check = false;
					break ;
				}
			}
			if (check) cnt++;
		}
		cout << "Data Set " << i + 1 << ":\n";
		cout << cnt << "/" << k << "\n\n";
	}
	return (0);
}