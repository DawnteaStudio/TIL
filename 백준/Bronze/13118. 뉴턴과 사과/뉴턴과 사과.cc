#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;

	int arr[4];
	for (int i = 0; i < 4; i++)
		cin >> arr[i];
	int x, y, r;
	cin >> x >> y >> r;
	for (int i = 0; i < 4; i++){
		if (arr[i] == x){
			cout << i + 1;
			return  (0);
		}
	}
	cout << 0;
}
