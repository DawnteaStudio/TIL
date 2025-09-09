#include <iostream>
#include <string>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct Time {
	int m;
	int s;
	int ms;

	Time(int new_m, int new_s, int new_ms) {
		m = new_m;
		s = new_s;
		ms = new_ms;
	}

	bool operator<(const Time &t) const {
		if (m == t.m) {
			if (s == t.s)
				return ms < t.ms;
			else return s < t.s;
		}
		else return m < t.m;
	}
};

int main()
{
	fast;
	string record, team;
	map<Time, string> record_lst;
	for (int i=0; i<8; i++) {
		cin >> record >> team;
		Time time = Time(stoi(record.substr(0,1)), stoi(record.substr(2, 2)), stoi(record.substr(5)));
		record_lst[time] = team;
	}
	int R=0, B=0, score[] = {10, 8, 6, 5, 4, 3, 2, 1}, seq=0;
	for (auto r : record_lst) {
		if (r.second == "R") R += score[seq];
		else B += score[seq];
		seq++;
	}
	if (R < B) cout << "Blue";
	else cout << "Red";
	return (0);
}
