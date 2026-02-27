#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
    cin >> n;
	int arr[] = {1, 2, 3};
	for (int i=0; i<n; i++) {
		if (i != n - 1 || n % 2 == 0)
            cout << arr[i % 2] << " ";
		else
            cout << arr[2];
	}
}