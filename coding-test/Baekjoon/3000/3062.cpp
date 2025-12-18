// 수 뒤집기
#include <iostream>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool isSymmetry(const string &number) {
	int size = (int)number.size();
	for (int i=0; i<=size; i++) {
		if (number[i] != number[size-i-1]) return false;
	}
	return true;
}

bool check(int number) {
	int tmp = number, r_number = 0;
	while (tmp) {
		r_number = r_number * 10 + tmp % 10;
		tmp /= 10;
	}

	int sum = number + r_number;
	return isSymmetry(to_string(sum));
}

int main()
{
	fast;
	int t; cin >> t;
	int number;
	for (int i=0; i<t; i++) {
		cin >> number;
		if (check(number)) cout << "YES\n";
		else cout << "NO\n";
	}
	return (0);
}