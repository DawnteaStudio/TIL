// 5와 6의 차이
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int five_to_six(int n) {
	string number = to_string(n);
	for (int i=0; i<(int)number.size(); i++) {
		if (number[i] == '5') number[i] = '6';
	}
	return stoi(number);
}

int six_to_five(int n) {
	string number = to_string(n);
	for (int i=0; i<(int)number.size(); i++) {
		if (number[i] == '6') number[i] = '5';
	}
	return stoi(number);
}

int main()
{
	fast;
	int a, b; cin >> a >> b;
	int min_value = six_to_five(a) + six_to_five(b);
	int max_value = five_to_six(a) + five_to_six(b);
	cout << min_value << " " << max_value;
	return (0);
}