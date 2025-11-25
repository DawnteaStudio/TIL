#include <iostream>
#include <string>
#include <deque>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	string str;
    while (true) {
		cin >> str;
		if (str[0] == '#')
			break;
		deque<char> d;
		int len = str.length();

		for (int i = 0; i < len; i++)
			d.push_back(str[i]);
		for (int i = 0; i < len; i++) {
			char f = d.front();
			if (f == 'a' || f == 'e' || f == 'i' || f == 'o' || f == 'u')
				break;
			d.pop_front();
			d.push_back(f);
		}

		for (int i = 0; i < len; i++) {
			cout << d.front();
			d.pop_front();
		}
		cout << "ay\n";
	}
}
