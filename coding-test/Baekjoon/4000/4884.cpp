#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long get_team(long long team)
{
	long long res = 1;
	while (res < team) {
		res *= 2;
	}
	return res - team;
}

long long get_match(long long match)
{
	long long tmp = 0;

	while (match > 0) {
		match /= 2;
		tmp += match;
	}
	return tmp;
}

int main()
{
	fast;
	long long g, a, t, d;
	while (true) {
		cin >> g >> t >> a >> d;
		if (g == -1 || t == -1 || a == -1 || d == -1)
			break;
		long long now_team = g * a + d;
		long long need_team = get_team(now_team);
		long long match = t * (t - 1) / 2 * g + get_match(now_team + need_team);
		cout << g << "*" << a << "/" << t << "+" << d << "=" << match << "+" << need_team << '\n';
	}
}