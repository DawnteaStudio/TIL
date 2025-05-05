#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int get_GCD(int a, int b)
{
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main()
{
	fast;
	vector<int> a(6);
	vector<int> b(6);
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	for (int i = 0; i < 6; i++)
		cin >> b[i];
	int son = 0, mom = 36;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (a[i] > b[j])
				son++;
		}
	}
	int gcd = get_GCD(son, mom);
	cout << son / gcd << "/" << mom / gcd << '\n';
}
