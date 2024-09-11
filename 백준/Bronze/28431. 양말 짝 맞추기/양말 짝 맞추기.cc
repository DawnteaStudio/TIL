#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n;
	int arr[10] = {0};
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		arr[n]++;
		if (arr[n] == 2)
			arr[n] = 0;
	}
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == 1)
		{
			cout << i;
			break;
		}
	}
}
