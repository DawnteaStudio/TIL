#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string number;

	while(true) {
		cin >> number;
		if (number == "0") break ;

		int width=2, size = number.size();
		width += size - 1;
		for (int i=0; i<size; i++) {
			if (number[i] == '1') width += 2;
			else if (number[i] == '0') width += 4;
			else width += 3;
		}
		cout << width << '\n';
	}
}
