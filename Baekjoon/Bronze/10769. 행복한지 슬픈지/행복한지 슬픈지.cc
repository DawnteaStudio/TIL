#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str;
	int happy = 0, sad = 0;
	getline(cin, str);
	int len = str.length();

	for (int i = 0; i < len; i++) {
		if (str[i] == ':') {
			if (i + 2 < len) {
				if (str[i + 1] == '-') {
					if (str[i + 2] == '(')
						sad++;
					else if (str[i + 2] == ')')
						happy++;
				}
			}
		}
	}
	if (happy > sad)
		cout << "happy";
	else if (happy < sad)
		cout << "sad";
	else if (happy != 0)
		cout << "unsure";
	else
		cout << "none";
}