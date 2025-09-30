#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[1001][3];

int main() {
	fast;
    
	int n;
	cin >> n;

	cin >> arr[0][0] >> arr[0][1] >> arr[0][2];

	for (int i = 1; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		arr[i][0] += min(arr[i - 1][1], arr[i - 1][2]);
		arr[i][1] += min(arr[i - 1][0], arr[i - 1][2]);
		arr[i][2] += min(arr[i - 1][0], arr[i - 1][1]);
	}
	cout << min(arr[n - 1][0], min(arr[n - 1][1], arr[n - 1][2]));
}
