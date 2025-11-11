// 꼬리를 무는 숫자 나열
#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_x(int n)
{
	int res = n / 4;
	res -= (n % 4 == 0);
	return res;
}

int find_y(int n)
{
	int res = n % 4 - 1;
	if (n % 4 == 0) res = 3;
	return res;
}

int main()
{
	fast;
	int a, b; cin >> a >> b;
	cout << abs(find_x(a) - find_x(b)) + abs(find_y(a) - find_y(b));
	return (0);
}