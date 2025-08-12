#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void make_lps(vector<int> &lps, string &p)
{
	int size = p.length();

	int start = 1;
	int j = 0;

	while (start < size) {
		if (p[start] == p[j]) {
			j++;
			lps[start] = j;
			start++;
		}
		else {
			if (j == 0) {
				lps[start] = 0;
				start++;
			}
			else
				j = lps[j - 1];
		}
	}
}

void KMP(vector<int> &cnt, vector<int> &lps, string &t, string &p)
{
	int t_index = 0;
	int p_index = 0;

	int t_len = t.length();
	int p_len = p.length();



	while (t_index < t_len) {
		if (t[t_index] == p[p_index]) {
			t_index++;
			p_index++;
			if (p_index == p_len) {
				cnt.push_back(t_index - p_len + 1);
				p_index = lps[p_index - 1];
			}
		}
		else {
			if (p_index == 0)
				t_index++;
			else
				p_index = lps[p_index - 1];
		}
	}
}

int main(void) {
	fast;

	string t, p;
	getline(cin, t);
	getline(cin, p);
	
	vector<int> lps(p.length(), 0);
	vector<int> cnt;
	make_lps(lps, p);
	KMP(cnt, lps, t, p);
	int size = cnt.size();
	cout << size << '\n';
	for (int i = 0; i < size; i++)
		cout << cnt[i] << ' ';
}

