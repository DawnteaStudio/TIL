#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, cnt=0; cin >> n;
	char arr[n], answer;
	for (int i=0; i<n; i++) cin >> arr[i];
	for (int i=0; i<n; i++) {
		cin >> answer;
		if (arr[i] == answer) cnt++;
	}
	cout << cnt;
}
