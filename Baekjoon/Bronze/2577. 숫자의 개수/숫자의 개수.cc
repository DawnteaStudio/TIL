#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;

	int arr[10] = {0};
	int a, b, c, res;
	cin >> a >> b >> c;
	res = a * b * c;
	while (res > 0)
	{
		arr[res % 10]++;
		res /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << arr[i] << '\n';
}
