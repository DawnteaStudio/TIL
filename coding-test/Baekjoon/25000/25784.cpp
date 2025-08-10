#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(void)
{
	fast;
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr + 3);

	if (arr[2] == arr[0] + arr[1])
		cout << 1;
	else if (arr[2] == arr[0] * arr[1])
		cout << 2;
	else
		cout << 3;
}