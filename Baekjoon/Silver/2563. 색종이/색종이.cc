#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, x, y, res = 0;
	cin >> n;
	
	int arr[100][100] = {0};
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		for (int i = y - 1; i < y + 9; i++)
		{
			for (int j = x - 1; j < x + 9; j++)
				arr[i][j] = 1;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (arr[i][j] == 1)
				res++;
		}
	}
	cout << res;
}
