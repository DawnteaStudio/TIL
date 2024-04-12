#include <iostream>
#include <algorithm>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	int num, k, tmp, res = 0;
	cin >> num >> k;
	int arr[num];
	int	input[num];

	for (int i = 0; i < num; i++)
	{
		if (i == 0)
			cin >> input[i];
		else
		{
			cin >> input[i];
			arr[i] = input[i] - input[i - 1];
		}
	}
	arr[0] = 0;
	sort(arr, arr + num);
	for (int i = 1; i <= num - k; i++)
		res += arr[i];
	cout << res;
}