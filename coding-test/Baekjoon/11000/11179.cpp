#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m;

void solve(int n)
{
	if (n < 2) {
		m = m * 2 + n;
		return ;
	}
	m = m * 2 + (n % 2);
	solve(n / 2);
}

int main()
{
	fast;
	cin >> n;
	solve(n);
	cout << m;
}
