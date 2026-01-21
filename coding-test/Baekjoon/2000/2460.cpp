// 지능형 기차 2
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, b, max_num = 0, total = 0;
	for (int i=0; i<10; i++) {
		cin >> a >> b;
		total += (b - a);
		max_num = max(max_num, total);
	}
	cout << max_num;
	return (0);
}