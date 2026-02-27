#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n; cin >> n;
	int arr[] = {0, 0}, num;
	for (int i=0; i<n; i++) {
		cin >> num;
		arr[num]++;
	}
	if (arr[0] < arr[1]) cout << "Junhee is cute!";
	else cout << "Junhee is not cute!";
	return (0);
}