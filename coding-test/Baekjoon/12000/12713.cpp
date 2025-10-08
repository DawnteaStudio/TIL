#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long arr[4] = {2, 3, 5, 7};
int res;

void get_total(vector<long long> &totals, vector<long long> &vec, long long v, int depth)
{
    int size = vec.size();
    if (depth == size) {
        totals.push_back(v);
        return;
    }
    
    get_total(totals, vec, v + vec[depth], depth + 1);
    get_total(totals, vec, v - vec[depth], depth + 1);
}

void solve(string &tmp, vector<long long> vec, int idx)
{
    int len = tmp.length();
    if (len == idx) {
        vector<long long> totals;
        get_total(totals, vec, vec[0], 1);
        int size = totals.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 4; j++) {
                if (totals[i] % arr[j] == 0) {
                    res++;
                    break;
                }
            }
        }
        return ;
    }
    for (int i =0; i + idx < len; i++) {
        long long v = 0;
        for (int j = idx; j <= idx + i; j++) {
            v = v * 10 + tmp[j] - '0';
        }
        vec.push_back(v);
        solve(tmp, vec, idx + i + 1);
        vec.pop_back();
    }
}

int main()
{
	fast;
	int n;
	string tmp;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
	    res = 0;
	    cin >> tmp;
	    vector<long long> vec;
	    solve(tmp, vec, 0);
	    cout << "Case #" << i << ": " << res << '\n';
	}
}