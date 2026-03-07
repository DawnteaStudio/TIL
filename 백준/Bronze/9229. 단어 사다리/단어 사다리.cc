#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(string& s1, string& s2) {
	if (s1.size() != s2.size())
        return false;
	int cnt = 0;
	for (int i=0; i<(int)s1.size(); i++) {
		if (s1[i] != s2[i])
            cnt++;
	}
	return cnt == 1;
}

bool game(string &begin) {
	string str;
	bool flag = true;
	while (true) {
		cin >> str;
		if (str == "#")
            break ;
		if (!cmp(begin, str))
			flag = false;
		begin = str;
	}
	return flag;
}

int main()
{
	fast;
	string str;
	while (true) {
		cin >> str;
		if (str == "#")
            break ;
		if (game(str))
            cout << "Correct\n";
		else
            cout << "Incorrect\n";
	}
}