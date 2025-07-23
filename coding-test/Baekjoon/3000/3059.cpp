#include <iostream>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int total = 0;
	for (int i = 65; i <= 90; i++)
		total += i;

	int n, tmp;
	cin >> n;

	string input;
	for (int i = 0; i < n; i++) {
		vector<bool> v(26, false);
		tmp = total;
		cin >> input;
		int size = input.length();
		for (int j = 0; j < size; j++) {
			if (v[input[j] - 'A'] == false) {
				v[input[j] - 'A'] = true;
				tmp -= input[j];
			}
		}
		cout << tmp << '\n';
	}
}
