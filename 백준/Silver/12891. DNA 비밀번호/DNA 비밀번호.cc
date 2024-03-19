#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void is_DNA_start(char ch, int &a, int &g, int &c, int &t, int &impurity)
{
	if (ch == 'A')
		a--;
	else if (ch == 'C')
		c--;
	else if (ch == 'G')
		g--;
	else if (ch == 'T')
		t--;
	else
		impurity--;
}

void is_DNA_end(char ch, int &a, int &g, int &c, int &t, int &impurity)
{
	if (ch == 'A')
		a++;
	else if (ch == 'C')
		c++;
	else if (ch == 'G')
		g++;
	else if (ch == 'T')
		t++;
	else
		impurity++;
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

	int a = 0, c = 0, g = 0, t = 0;
	int start = 0, end = window - 1;
	for (int i = 0; i < window; i++)
	{
		if (str[i] == 'A')
			a++;
		else if (str[i] == 'C')
			c++;
		else if (str[i] == 'G')
			g++;
		else if (str[i] == 'T')
			t++;
		else
			impurity++;
	}

	if (A <= a && C <= c && G <= g && T <= t && impurity == 0)
		res++;
	for (int i = start; i < len - window; i++)
	{
		is_DNA_start(str[i], a, g, c, t, impurity);
		end++;
		is_DNA_end(str[end], a, g, c, t, impurity);
		if (A <= a && C <= c && G <= g && T <= t && impurity == 0)
			res++;
	}
	cout << res;
}