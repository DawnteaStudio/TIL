#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int arr[4];
	for (int i=0; i<4; i++) cin >> arr[i];
	sort(arr, arr + 4);
	cout << arr[0] * arr[2];
	return (0);
}