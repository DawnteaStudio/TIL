#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main() {
	fast;
	int n;
	cin >> n;
	int D = 0, P = 0;
	string tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp == "D")
			D++;
		else
			P++;
		if (D - P >= 2 || P - D >= 2)
			break;
	}
	cout << D << ":" << P;
}
