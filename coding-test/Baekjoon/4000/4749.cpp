#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	double a, r;
	string v, u;
	vector<string> lst;

	while (true) {
		cin >> a >> u >> r;
		cin.ignore();
		getline(cin, v);
		if (a < 0.0) break ;

		cout.precision(1);
		cout << fixed;
		double p = (a / r * 100.0);
		if (p < 1.0) lst.push_back(v);
		else cout << v << " " << a << " " << u << " " << (int)round(p) << "%\n";
	}

	if (lst.empty()) return (0);
	cout << "Provides no significant amount of:\n";
	for (int i=0; i<(int)lst.size(); i++) cout << lst[i] << '\n';
	return (0);
}