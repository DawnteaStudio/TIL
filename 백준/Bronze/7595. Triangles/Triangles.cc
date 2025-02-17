#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int input;
	while (true) {
		cin >> input;
		if (input == 0)
			break;
		for (int i = 1; i <= input; i++) {
			for (int j = 0; j < i; j++)
				cout << '*';
			cout << '\n';
		}
	}
}