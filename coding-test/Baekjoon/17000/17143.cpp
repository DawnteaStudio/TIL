#include <iostream>
#include <vector>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct shark {
	int r;
	int c;
	int s;
	int d;
	int z;
	bool die;
};

int main()
{
	fast;
	int row, col, m, res = 0;

	cin >> row >> col >> m;

	vector<shark> ss;

	vector<vector<pair<int, int> > > sea(row + 1, vector<pair<int, int> >(col + 1));

	int r, c, s, d, z;
	int catch_y, catch_x;
	int cri_r = (row - 1) * 2, cri_c = (col - 1) * 2;

	for (int rr = 1; rr <= row; rr++) {
		for (int cc = 1; cc <= col; cc++)
			sea[rr][cc] = make_pair(0, -1);
	}

	for (int i = 0; i < m; i++) {
		cin >> r >> c >> s >> d >> z;
		if (d == 1 || d == 2) {
			if (cri_r != 0)
				s %= cri_r;
			else
				s = 0;
		}
		else {
			if (cri_c != 0)
				s %= cri_c;
			else
				s = 0;
		}
		shark tmp = { r, c, s, d, z, false };
		sea[r][c] = make_pair(z, i);
		ss.push_back(tmp);
	}

	for (int i = 1; i <= col; i++) {
		catch_y = catch_x = -1;
		for (int k = 1; k <= row; k++) {
			if (sea[k][i].first == 0)
				continue;
			else {
				res += sea[k][i].first;
				catch_y = k;
				catch_x = i;
				sea[k][i].first = 0;
				sea[k][i].second = -1;
				break;
			}
		}

		for (int rr = 1; rr <= row; rr++) {
			for (int cc = 1; cc <= col; cc++)
				sea[rr][cc] = make_pair(0, -1);
		}

		int size = ss.size();
		for (int k = 0; k < size; k++) {
			shark *now = &ss[k];
			if ((*now).die)
				continue;
			int move = (*now).s;
			if ((*now).c == catch_x && (*now).r == catch_y) {
				(*now).die = true;
			}
			else {
				if (move != 0) {
					if ((*now).d == 1) {
						if ((*now).r > move) {
							(*now).r -= move;
						}
						else {
							move -= ((*now).r - 1);
							(*now).r = 1;
							(*now).d++;
							if (move > 0) {
								(*now).r += move;
								if ((*now).r > row) {
									(*now).d--;
									move -= (row - 1);
									(*now).r = row;
									(*now).r -= move;
								}
							}
						}
					}
					else if ((*now).d == 2) {
						if ((*now).r + move <= row) {
							(*now).r += move;
						}
						else {
							move -= (row - (*now).r);
							(*now).r = row;
							(*now).d--;
							if (move > 0) {
								(*now).r -= move;
								if ((*now).r <= 0) {
									(*now).d++;
									move -= (row - 1);
									(*now).r = 1;
									(*now).r += move;
								}
							}
						}
					}
					else if ((*now).d == 3) {
						if ((*now).c + move <= col) {
							(*now).c += move;
						}
						else {
							move -= (col - (*now).c);
							(*now).c = col;
							(*now).d++;
							if (move > 0) {
								(*now).c -= move;
								if ((*now).c <= 0) {
									(*now).d--;
									move -= (col - 1);
									(*now).c = 1;
									(*now).c += move;
								}
							}
						}
					}
					else if ((*now).d == 4) {
						if ((*now).c > move) {
							(*now).c -= move;
						}
						else {
							move -= ((*now).c - 1);
							(*now).c = 1;
							(*now).d--;
							if (move > 0) {
								(*now).c += move;
								if ((*now).c > col) {
									(*now).d++;
									move -= (col - 1);
									(*now).c = col;
									(*now).c -= move;
								}
							}
						}
					}
				}

				if (sea[(*now).r][(*now).c].first < (*now).z) {
					sea[(*now).r][(*now).c].first = (*now).z;
					if (sea[(*now).r][(*now).c].second != -1)
						ss[sea[(*now).r][(*now).c].second].die = true;
					sea[(*now).r][(*now).c].second = k;
				}
				else {
					ss[k].die = true;
				}
			}
		}
	}

	cout << res;
}