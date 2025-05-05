#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, tmp, total;
	bool	magic = true;

	int arr[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cin >> arr[i][j];
	}
	total = arr[0][0] + arr[0][1] + arr[0][2] + arr[0][3];
	for (int i = 0; i < 4; i++)
	{
		tmp = 0;
		for (int j = 0; j < 4; j++)
			tmp += arr[i][j];
		if (tmp != total)
		{
			magic = false;
			break;
		}
		tmp = 0;
		for (int j = 0; j < 4; j++)
			tmp += arr[j][i];
		if (tmp != total)
		{
			magic = false;
			break;
		}
	}
	if (magic)
		cout << "magic";
	else
		cout << "not magic";
}
