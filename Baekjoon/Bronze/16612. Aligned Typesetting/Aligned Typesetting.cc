#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	long long words, len, cnt = 0;
	cin >> words >> len;

	string input;
	if (words == 1) {
		cin >> input;
		if (input.length() == len)
			cout << "Yes";
		else
			cout << "No";
	}
	else {
		for (long long i = 0; i < words; i++) {
			cin >> input;
			cnt += input.length();
		}
		if (cnt >= len)
			cout << "No";
		else if ((len - cnt) % (words - 1) != 0)
			cout << "No";
		else
			cout << "Yes";
	}
}