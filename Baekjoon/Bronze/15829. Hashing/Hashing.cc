#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

#define R 31
#define M 1234567891

long long ft_pow(int n)
{
	long long res = 1;
	for (int i = 0; i < n; i++)
		res = (res * R) % M;
	return res;
}

int main() {
	fast;
	long long n, hash = 0;
	string str;
	cin >> n >> str;

	for (int i = 0; i < n; i++)
	{
		hash += ((str[i] - 'a' + 1) * ft_pow(i)) % M;
		hash %= M;
	}
	cout << hash;
}

