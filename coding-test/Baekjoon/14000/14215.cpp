#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[3];

int main() {
	fast;
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr + 3);

	if (arr[0] + arr[1] > arr[2])
		cout << arr[0] + arr[1] + arr[2];
	else
		cout << (arr[0] + arr[1]) * 2 - 1;
}
