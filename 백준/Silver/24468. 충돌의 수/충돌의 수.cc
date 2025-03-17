#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
	return a.first < b.first;
}

int main()
{
	fast;
	int l, n, t, cnt = 0;
	cin >> l >> n >> t;
	vector<pair<int, int> > ball;
	vector<int> box(l + 1, 0);

	int pos;
	char dir;
	for (int i = 0; i < n; i++) {
		cin >> pos >> dir;
		if (dir == 'R')
			ball.push_back(make_pair(pos, 1));
		else
			ball.push_back(make_pair(pos, -1));
		box[pos] = 1;
	}
	sort(ball.begin(), ball.end(), cmp);

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n; j++) {
			box[ball[j].first] = 0;
			pos = ball[j].first + ball[j].second;
			if (pos == 0 || pos == l)
				ball[j].second *= -1;
			else {
				if (box[pos] == 1) {
					ball[j].second = 1;
					ball[j - 1].second = -1;
					cnt++;
				}
			}
			ball[j].first = pos;
			box[pos] = 1;
		}
	}
	cout << cnt;
}