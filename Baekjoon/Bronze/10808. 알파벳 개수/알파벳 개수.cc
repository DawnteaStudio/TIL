#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int alpha[26] = {0};

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
		alpha[str[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		cout << alpha[i] << ' ';
}