#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(pair<char, int> &a, pair<char, int> &b)
{
    if (a.second > b.second)
        return true;
    if (a.second == b.second)
        return a.first < b.first;
    return false;
}

int main()
{
	fast;
	int n, m = 0;
	cin >> n;
	
	map<int, map<char, int> > idx_to_map;

	string str;
	for (int i = 0; i < n; i++) {
	    cin >> str;
	    int len = str.length();
	    if (m < len)
	        m = len;
	    for (int j = 0; j < len; j++) {
	        if (idx_to_map.find(j + 1) == idx_to_map.end()) {
	            idx_to_map[j + 1][str[j]] = 1;
	        }
	        else {
	            if (idx_to_map[j + 1].find(str[j]) == idx_to_map[j + 1].end())
	                idx_to_map[j + 1][str[j]] = 1;
	            else
	                idx_to_map[j + 1][str[j]]++;
	        }
	    }
	}
	
	for (int i = 1; i <= m; i++) {
	    vector<pair<char, int> > tmp;
	    
	    map<char, int>::iterator iter = idx_to_map[i].begin();
	    for (;iter != idx_to_map[i].end(); iter++) {
	        tmp.push_back({iter->first, iter->second});
	    }
	    
	    sort(tmp.begin(), tmp.end(), cmp);
	    int high = tmp[0].second;
	    int cnt = tmp.size();
	    
	    cout << i << ": ";
	    for (int j = 0; j < cnt; j++) {
	        if (tmp[j].second == high)
	            cout << tmp[j].first << " ";
	       else
	            break;
	    }
	    cout << '\n';
	}
}