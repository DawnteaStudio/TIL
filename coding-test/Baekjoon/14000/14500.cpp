#include <iostream>
#include <vector>
#include <string>
#include <set>
#define fast ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int res;
set<string> s;
vector<vector<vector<int> > > mino;

void init()
{
	mino.push_back({ {1, 1, 1, 1} });
	s.insert("1,4:1111");
	mino.push_back({ {1, 1}, {1, 1} });
	s.insert("2,2:1111");
	mino.push_back({ {1, 0}, {1, 0}, {1, 1} });
	s.insert("3,2:101011");
	mino.push_back({ {1, 0}, {1, 1}, {0, 1} });
	s.insert("3,2:101101");
	mino.push_back({ {1, 1, 1}, {0, 1, 0} });
	s.insert("2,3:111010");
}

void solve(vector<vector<int> > &v, int n, int m)
{
	int size = mino.size();

	for (int i = 0; i < size; i++) {
		int h = mino[i].size();
		int w = mino[i][0].size();
		int tmp;
		for (int y = 0; y <= n - h; y++) {
			for (int x = 0; x <= m - w; x++) {
				tmp = 0;

				for (int mino_y = 0; mino_y < h; mino_y++) {
					for (int mino_x = 0; mino_x < w; mino_x++) {
						if (mino[i][mino_y][mino_x] == 1) {
							tmp += v[y + mino_y][x + mino_x];
						}
					}
				}
				if (tmp > res)
					res = tmp;
			}
		}
	}
}

void get_key(vector<vector<int> > v)
{
	string res;
	int h = v.size();
	int w = v[0].size();

	res += (char)(h + '0');
	res += ",";
	res += (char)(w + '0');
	res += ":";

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			res += (char)(v[i][j] + '0');
	}
	if (s.find(res) == s.end()) {
		s.insert(res);
		mino.push_back(v);
	}
}

void rotate()
{
	int size = mino.size();

	for (int idx = 0; idx < size; idx++) {
		vector<vector<int> > shape = mino[idx];
		vector<vector<int> > tmp;

		for (int i = 0; i < 4; i++) {
			tmp.clear();
			int h = shape.size();
			int w = shape[0].size();

			tmp.resize(w);
			for (int j = 0; j < w; j++) {
				tmp[j].resize(h);
			}

			for (int p = 0; p < h; p++) {
				for (int q = 0; q < w; q++) {
					tmp[q][h - p - 1] = shape[p][q];
				}
			}
			shape = tmp;
			get_key(tmp);
		}
	}

}

void swap()
{
	for (int idx = 0; idx < 5; idx++) {
		vector<vector<int> > shape = mino[idx];
		vector<vector<int> > tmp;

		int h = shape.size();
		int w = shape[0].size();

		tmp.resize(h);
		for (int j = 0; j < h; j++) {
			tmp[j].resize(w);
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				tmp[i][w - j - 1] = shape[i][j];
			}
		}
		get_key(tmp);
	}
}

int main() {
	fast;

	int n, m;
	cin >> n >> m;

	vector<vector<int> > v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	init();
	swap();
	rotate();
	solve(v, n, m);
	cout << res;
}
