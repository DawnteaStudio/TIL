#include <iostream>
#include <cmath>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string chess1, chess2;
	cin >> chess1 >> chess2;

	int a = chess1[0];
	int b = chess1[1];
	int c = chess2[0];
	int d = chess2[1];

	if (abs(a - c) < abs(b - d))
		cout << abs(a - c) << " " << abs(b - d) << '\n';
	else
		cout << abs(b - d) << " " << abs(a - c) << '\n';
}