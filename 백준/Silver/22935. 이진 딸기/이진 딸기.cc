#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

string find_binary_num(int num) {
	string result;
	while (num) {
		result = to_string(num % 2) + result;
		num /= 2;
	}
	string zero = "0000";
	result = zero.substr(0, 4 - result.size()) + result;
	return result;
}

int main()
{
	fast;
	int t; cin >> t;
	int n;
	for (int i=0; i<t; i++) {
		cin >> n;
		int tmp = n % 28 == 0 ? 28 : n % 28;
		tmp = tmp > 15 ? 30 - tmp : tmp;
		string binary_num = find_binary_num(tmp);
		for (int j=0; j<4; j++) {
			if (binary_num[j] == '0') cout << "V";
			else cout << "딸기";
		}
		cout << '\n';
	}
	return (0);
}
