#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int y_1, m_1, d_1, y_2, m_2, d_2;
	cin >> y_1 >> m_1 >> d_1 >> y_2 >> m_2 >> d_2;

	if (y_2 > y_1) {
		if (m_2 > m_1)
			cout << y_2 - y_1 << "\n";
		else if (m_2 == m_1) {
			if (d_2 >= d_1)
				cout << y_2 - y_1 << "\n";
			else
				cout << y_2 - y_1 - 1<< "\n";
		}
		else
			cout << y_2 - y_1 - 1 << "\n";
	}
	else
		cout << 0 << '\n';
	cout << y_2 - y_1 + 1 << "\n";
	cout << y_2 - y_1;
}