#include <iostream>
#include <string>
#include <map>
#include <deque>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool isC(map<char, bool> bm)
{
    if (bm['S'] && bm['K'] && bm['H'])
        return true;
    return false;
}

int main()
{
	fast;
	string str;
	cin >> str;
	map<char, char> m;
	map<char, bool> bm;
	m['R'] = 'S';
	m['B'] = 'K';
	m['L'] = 'H';
	bm['S'] = false;
	bm['K'] = false;
	bm['H'] = false;
	
	int len = str.length();
	if (len < 3) {
	    for (int i = 0; i < len; i++)
	        cout << m[str[i]];
	}
	else {
        deque<char> d;
        for (int i = 0; i < len; i++) {
            char c = m[str[i]];
            if (d.empty()) {
                d.push_back(c);
                bm[c] = true;
            }
            else if (bm[c] == true) {
                while (d.front() != c) {
                    cout << d.front();
                    bm[d.front()] = false;
                    d.pop_front();
                }
                cout << d.front();
                d.pop_front();
                d.push_back(c);
            }
            else if (d.size() == 2) {
                bm['S'] = false;
	            bm['K'] = false;
	            bm['H'] = false;
	            d.clear();
                cout << 'C';
            }
            else {
                bm[c] = true;
                d.push_back(c);
            }
        }
        
        while(!d.empty()) {
            cout << d.front();
            d.pop_front();
        }
	}
}