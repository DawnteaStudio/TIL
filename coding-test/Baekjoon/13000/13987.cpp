#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int first[6], second[6];
	for (int i=0; i<6; i++) cin >> first[i];
	for (int i=0; i<6; i++) cin >> second[i];

	int cnt = 0, total = 36;
	for (int i=0; i<6; i++) {
		for (int j=0; j<6; j++) {
			if (first[i] > second[j]) cnt++;
			else if (first[i] == second[j]) total--;
		}
	}

	double res = (double)cnt / total;
	cout.precision(5);
	cout << fixed;
	cout << double(round(res * 100000)) / 100000.0;
	return (0);
}