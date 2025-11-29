// Document
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int min_days = -1;

void check_range(int &num, int &date) {
	if (num == 5) {
		num = 0;
		date += 2;
	}
}

void find_min_days(int arr[][5], int n, int cnt, int idx, int date) {
	if (cnt == n) {
		min_days = date;
		return ;
	}
	check_range(idx, date);
	while (true) {
		if (arr[cnt][idx] == 1) {
			find_min_days(arr, n, cnt + 1, idx + 1, date + 1);
			break ;
		}
		check_range(++idx, ++date);
	}
}

int main()
{
	fast;
	int n; cin >> n;
	int arr[50][5];
	for (int i=0; i<n; i++) {
		for (int j=0; j<5; j++) cin >> arr[i][j];
	}
	find_min_days(arr, n, 0, 0, 0);
	cout << min_days;
	return (0);
}