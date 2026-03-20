#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct RES_PAIR {
	int a, b, c, d;
};

bool cmp(RES_PAIR &r1, RES_PAIR &r2) {
	if (r1.a == r2.a)
        return r1.b < r2.b;
	else
        return r1.a < r2.a;
}

int main()
{
	fast;
	int arr[101] = {0};
	vector<RES_PAIR> res_pair;
	map<int, int> cube;
	for (int i=2; i<=100; i++)
	{
		arr[i] = (int)pow(i, 3);
		cube[arr[i]] = i;
	}
	for (int i=2; i<98; i++) {
		for (int j=i + 1; j<99; j++) {
			for (int k=j + 1; k<100; k++) {
				int tmp = arr[i] + arr[j] + arr[k];
				if (cube.find(tmp) != cube.end())
					res_pair.push_back({cube[tmp], i, j, k});
			}
		}
	}
	sort(res_pair.begin(), res_pair.end(), cmp);
	for (int i=0; i<(int)res_pair.size(); i++) {
		cout << "Cube = " << res_pair[i].a << ", Triple = ("
		<< res_pair[i].b << "," << res_pair[i].c << "," << res_pair[i].d << ")\n";
	}
}