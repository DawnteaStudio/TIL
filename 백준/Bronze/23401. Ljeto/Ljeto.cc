#include <iostream>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, pine = 0, blue = 0;
	map<int, int> last_pine;
	map<int, int> last_blue;
	cin >> n;

	int t, a, b;
	for (int i = 0; i < n; i++) {
		cin >> t >> a >> b;
		if (a < 5) {
			if (last_pine.find(a) == last_pine.end()) {
				pine += 100;
			}
			else if (t - last_pine[a] <= 10)
				pine += 150;
			else
				pine += 100;
			last_pine[a] = t;
		}
		else {
			if (last_blue.find(a) == last_blue.end()) {
				blue += 100;
			}
			else if (t - last_blue[a] <= 10)
				blue += 150;
			else
				blue += 100;
			last_blue[a] = t;
		}
	}
	cout << pine << " " << blue;
}