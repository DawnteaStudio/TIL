#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n;
	char c, tmp;
	cin >> n;

	int arr[4] = {0};
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		switch (c)
		{
			case 'C':
				arr[0]++;
				break;
			case 'S':
				arr[1]++;
				break;
			case 'I':
				arr[2]++;
				break;
			case 'A':
				arr[3]++;
				break;
		}
	}
	cin >> tmp;
	switch (tmp)
	{
		case 'C':
			cout << arr[0];
			break;
		case 'S':
			cout << arr[1];
			break;
		case 'I':
			cout << arr[2];
			break;
		case 'A':
			cout << arr[3];
			break;
	}
}
