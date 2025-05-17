#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, f; cin >> n >> f;

	int xi, vi;
	double arr[n];
	for (int i=0; i<n; i++) {
		cin >> xi >> vi;
		arr[i] = (double)(f - xi) / vi;
	}

	int res_idx = 0;
	for (int i=1; i<n; i++) {
		if (arr[res_idx] > arr[i]) res_idx = i;
	}
	cout << res_idx + 1;
	return (0);
}