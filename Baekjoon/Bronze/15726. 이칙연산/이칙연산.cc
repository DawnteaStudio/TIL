#include <iostream>
#include<algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	double A, B, C;
	cin >> A >> B >> C;
	
	cout << (int)max({ (A * B / C), (A / B * C) });
}
