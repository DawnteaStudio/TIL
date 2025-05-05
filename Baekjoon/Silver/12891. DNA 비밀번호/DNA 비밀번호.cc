#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void is_DNA_start(char c, int &A, int &G, int &C, int &T)
{
	if (c == 'A')
		A++;
	else if (c == 'C')
		C++;
	else if (c == 'G')
		G++;
	else if (c == 'T')
		T++;

}

void is_DNA_end(char c, int &A, int &G, int &C, int &T)
{
	if (c == 'A')
		A--;
	else if (c == 'C')
		C--;
	else if (c == 'G')
		G--;
	else if (c == 'T')
		T--;
}

int main()
{
	fast;
	int len, window, res = 0;
	cin >> len >> window;
	string str;
	cin >> str;

	int A, C, G, T, impurity = 0;
	cin >> A >> C >> G >> T;

	int start = 0, end = window - 1;
	for (int i = 0; i < window; i++)
	{
		if (str[i] == 'A')
			A--;
		else if (str[i] == 'C')
			C--;
		else if (str[i] == 'G')
			G--;
		else if (str[i] == 'T')
			T--;
	}

	if (A <= 0 && C <= 0 && G <= 0 && T <= 0)
		res++;
	for (int i = start; i < len - window; i++)
	{
		is_DNA_start(str[i], A, G, C, T);
		end++;
		is_DNA_end(str[end], A, G, C, T);
		if (A <= 0 && C <= 0 && G <= 0 && T <= 0)
			res++;
	}
	cout << res;
}