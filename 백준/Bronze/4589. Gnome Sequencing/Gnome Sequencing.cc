#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n;
	cin >> n;
	cout << "Gnomes:\n";

	int arr[3];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> arr[j];
		if (arr[0] < arr[1] && arr[1] < arr[2])
			cout << "Ordered\n";
		else if (arr[0] > arr[1] && arr[1] > arr[2])
			cout << "Ordered\n";
		else
			cout << "Unordered\n";
	}
	
}
