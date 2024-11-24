#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	int s1 = 1, s2 = 2, s3 = 3;
	int res1 = 0, res2 = 0, res3 = 0;
	cin >> n;

	int a, b, g;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> g;
		if (s1 == a || s1 == b)
			s1 = a + b - s1;
		if (s2 == a || s2 == b)
			s2 = a + b - s2;
		if (s3 == a || s3 == b)
			s3 = a + b - s3;
		if (s1 == g)
			res1++;
		if (s2 == g)
			res2++;
		if (s3 == g)
			res3++;
	}
	cout << (res1 > res2 ? (res1 > res3 ? res1 : res3) : (res2 > res3 ? res2 : res3));
}
