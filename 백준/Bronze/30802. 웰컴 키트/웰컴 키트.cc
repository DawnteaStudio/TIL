#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int N;
	cin >> N;
	int s, m, l, xl,xxl, xxxl;
	cin >> s >> m >> l >> xl >> xxl >> xxxl;
	int T, P;
	cin >> T >> P;

	int resT = 0, resP = 0, resP_ = 0;

	resT += s / T;
	if (s % T != 0)
		resT++;
	resT += m / T;
	if (m % T != 0)
		resT++;
	resT += l / T;
	if (l % T != 0)
		resT++;
	resT += xl / T;
	if (xl % T != 0)
		resT++;
	resT += xxl / T;
	if (xxl % T != 0)
		resT++;
	resT += xxxl / T;
	if (xxxl % T != 0)
		resT++;
	resP = N / P;
	resP_ = N % P;
	cout << resT << '\n' << resP << ' ' << resP_;
}