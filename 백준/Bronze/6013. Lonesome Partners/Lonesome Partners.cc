#include <iostream>
#include <vector>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct POS {
	int x, y;
};

int find_dist(POS &p1, POS &p2) {
	return (int)sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main()
{
	fast;
	int n, x, y;
    cin >> n;
	vector<POS> pos;
	for (int i=0; i<n; i++) {
		cin >> x >> y;
		pos.push_back({x, y});
	}
	int max_dist = 0;
	pair<int, int> res;
	for (int i=0; i<n-1; i++) {
		for (int j=i+1; j<n; j++) {
			int tmp = find_dist(pos[i], pos[j]);
			if (tmp > max_dist) {
				max_dist = tmp;
				res.first = i + 1;
				res.second = j + 1;
			}
		}
	}
	cout << res.first << " " << res.second;
}