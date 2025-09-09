#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int min_area = -1;

int cal_area(int a, int b, int c) {
	return a * b * 2 + a * c * 2 + b * c * 2;
}

int main()
{
	fast;
	int n; cin >> n;
	int arr[3] = {0};
	for (int i=1; i<=n; i++) {
		if (n % i != 0) continue ;
		int tmp = n / i;
		for (int j=1; j<=tmp/j; j++) {
			if (tmp % j != 0) continue ;
			int new_area = cal_area(i, j, tmp / j);
			if (min_area == -1 || min_area > new_area) {
				min_area = new_area;
				arr[0] = i;
				arr[1] = j;
				arr[2] = tmp / j;
			}
		}
	}
	for (int i=0; i<3; i++) cout << arr[i] << " ";
	return (0);
}
