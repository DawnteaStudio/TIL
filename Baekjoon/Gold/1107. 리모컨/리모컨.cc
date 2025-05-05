#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool	avil(int *arr, int num)
{
	string tmp = to_string(num);
	for (int i = 0; i < tmp.length(); i++)
	{
		if (arr[(int)(tmp[i] - '0')] == 1)
			return (false);
	}
	return (true);
}

int main()
{
	string num;
	cin >> num;
	int arr[10] = {0};
	int m, key;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> key;
		arr[key] = 1;
	}

	int res = abs(stoi(num) - 100);
	int int_num = stoi(num);

	for (int i = 0; i < 1000000; i++)
	{
		if (avil(arr, i))
		{
			if (res > abs(int_num - i) + to_string(i).length())
				res = abs(int_num - i) + to_string(i).length();
		}
	}
	cout << res;
}