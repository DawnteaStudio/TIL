#include <iostream>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int arr[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
	string a, b;
	cin >> a >> b;
	int len = a.length();
	vector<int> vec(2 * len);
	for (int i = 0; i < len; i++) {
		vec[i * 2] = arr[a[i] - 'A'];
		vec[i * 2 + 1] = arr[b[i] - 'A']; 
	}

	for (int i = 2 * len; i != 2; i--) {
		for (int j = 0; j < i - 1; j++)
			vec[j] = (vec[j] + vec[j + 1]) % 10;
	}
	cout << vec[0] << vec[1];
}