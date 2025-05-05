#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main() {
	fast;
	string input;
	int y, n, a, p;
	while (true)
	{
		y = 0, n = 0, a = 0, p = 0;
		cin >> input;
		if (input == "#")
			break;
		int len = input.length();
		for (int i = 0; i < len; i++)
		{
			if (input[i] == 'Y')
				y++;
			else if (input[i] == 'N')
				n++;
			else if (input[i] == 'A')
				a++;
			else if (input[i] == 'P')
				p++;
		}
		if (a * 2 >= len)
			cout << "need quorum" << endl;
		else if (y > n)
			cout << "yes" << endl;
		else if (y < n)
			cout << "no" << endl;
		else
			cout << "tie" << endl;
	}
}
