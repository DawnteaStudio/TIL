#include <iostream>
#include <string>
#include <cmath>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long solve(string &str, int num, int len)
{
	long long res = 0;
	for (int i = 0; i < len; i++) {
		int v = str[i] - '0';
		res += v * pow(num, len - i - 1);
	}
	return res;
}

int main()
{
	fast;
	string two, three;
	cin >> two >> three;

	long long v_two = 0 , v_three = 0;
	int two_len = two.length();
	int thr_len = three.length();

	v_two = solve(two, 2, two_len);
	v_three = solve(three, 3, thr_len);

	map<long long, int> m_two;

	for (int i = 0; i < two_len; i++) {
		if (two[i] == '0')
			m_two.insert(make_pair(v_two + pow(2, two_len - i - 1), 1));
		else
			m_two.insert(make_pair(v_two - pow(2, two_len - i - 1), 1));
	}

	for (int i = 0; i < thr_len; i++) {
		long long tmp = pow(3, thr_len - i - 1);
		if (three[i] == '2') {
			if (m_two.find(v_three - tmp) != m_two.end()) {
				cout << v_three - tmp;
				break;
			}
			if (m_two.find(v_three - 2 * tmp) != m_two.end()) {
				cout << v_three - 2 * tmp;
				break;
			}
		}
		else if (three[i] == '1') {
			if (m_two.find(v_three + tmp) != m_two.end()) {
				cout << v_three + tmp;
				break;
			}
			if (m_two.find(v_three - tmp) != m_two.end()) {
				cout << v_three - tmp;
				break;
			}
		}
		else if (three[i] == '0') {
			if (m_two.find(v_three + tmp) != m_two.end()) {
				cout << v_three + tmp;
				break;
			}
			if (m_two.find(v_three + 2 * tmp) != m_two.end()) {
				cout << v_three + 2 * tmp;
				break;
			}
		}
	}
}
