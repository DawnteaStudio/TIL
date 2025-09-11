#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int res = -1;
int arr[20];

bool isCarry(int a, int b, int c) {
	bool flag = false;
	while (a || b || c) {
		if ((a % 10) + (b % 10) + (c % 10) >= 10) {
			flag = true;
			break;
		}
		a /= 10;
		b /= 10;
		c /= 10;
	}
	return flag;
}

int main() {
	fast;
    
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int p = j + 1; p < n; p++) {
				if (isCarry(arr[i], arr[j], arr[p]))
					continue;
				if (res < arr[i] + arr[j] + arr[p])
					res = arr[i] + arr[j] + arr[p];
			}
		}
	}
	cout << res;
}
