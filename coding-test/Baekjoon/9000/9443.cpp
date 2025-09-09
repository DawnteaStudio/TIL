#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[26];

int main() {
	fast;
    int n;
	cin >> n;

	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr[tmp[0] - 'A']++;
	}
	
	int cnt = 0;
	int idx = 0;
	while (cnt < n && cnt < 26) {
		if (arr[idx] > 0) {
			arr[idx]--;
			idx++;
		}
		else
			break;
		cnt++;
	}
	cout << cnt;
}
