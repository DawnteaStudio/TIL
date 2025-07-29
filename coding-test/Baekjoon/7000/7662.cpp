#include <iostream>
#include <queue>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

struct cmp {
	bool operator()(long long a, long long b) {
		return a > b;
	}
};

int main() {
	fast;

	long long t, k, v;
	cin >> t;

	char c;
	while (t--) {
		cin >> k;
		priority_queue<long long> max_q;
		priority_queue<long long, vector<long long>, cmp> min_q;
		map<long long, long long> m;

		for (int i = 0; i < k; i++) {
			cin >> c >> v;
			if (c == 'I') {
				max_q.push(v);
				min_q.push(v);
				if (m.find(v) == m.end())
					m[v] = 1;
				else
					m[v]++;
			}
			else if (c == 'D') {
				if (max_q.empty() || min_q.empty())
					continue;
				if (v == 1) {
					while (!max_q.empty() && m[max_q.top()] == 0)
						max_q.pop();
					if (max_q.empty())
						continue;
					m[max_q.top()]--;
					max_q.pop();
				}
				else {
					while (!min_q.empty() && m[min_q.top()] == 0)
						min_q.pop();
					if (min_q.empty())
						continue;
					m[min_q.top()]--;
					min_q.pop();
				}

			}
		}
		while (!max_q.empty() && m[max_q.top()] == 0)
			max_q.pop();
		while (!min_q.empty() && m[min_q.top()] == 0)
			min_q.pop();
		if (max_q.empty() || min_q.empty())
			cout << "EMPTY\n";
		else {
			cout << max_q.top() << " " << min_q.top() << '\n';
		}
	}
}
