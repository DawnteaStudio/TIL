#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
	fast;
	string tmp;

	string s_h, s_m, s_s;
	cin >> s_h >> tmp >> s_m >> tmp >> s_s;
	string e_h, e_m, e_s;
	cin >> e_h >> tmp >> e_m >> tmp >> e_s;

	if (stoi(s_h) > stoi(e_h)) {
		e_h = to_string(stoi(e_h) + 24);
	} else if (stoi(s_h) == stoi(e_h) && stoi(s_m) > stoi(e_m)) {
		e_h = to_string(stoi(e_h) + 24);
	} else if (stoi(s_h) == stoi(e_h) && stoi(s_m) == stoi(e_m) && stoi(s_s) > stoi(e_s)) {
		e_h = to_string(stoi(e_h) + 24);
	}

	int s = stoi(s_h) * 3600 + stoi(s_m) * 60 + stoi(s_s);
	int e = stoi(e_h) * 3600 + stoi(e_m) * 60 + stoi(e_s);
	int t = e - s;
	cout << t;
}
