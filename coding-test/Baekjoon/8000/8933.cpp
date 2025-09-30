#include <iostream>
#include <string>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, res;

string make_string(int arr[4])
{
    string tmp = "A" + to_string(arr[0]) + "G" + to_string(arr[1]) + "T" + to_string(arr[2]) + "C" + to_string(arr[3]);
    return tmp;
}

int get_idx(char c)
{
    if (c == 'A')
        return 0;
    else if (c == 'G')
        return 1;
    else if (c == 'T')
        return 2;
    return 3;
}

int main() {
	fast;
    
    cin >> n;
    int k;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> k >> str;

        int arr[4] = {0, };
        map<string, int> m;
        res = 1;
        for (int j = 0; j < k; j++) {
            arr[get_idx(str[k])]++;
        }
        string tmp = make_string(arr);
        m[tmp] = 1;

        int len = str.length();
        for (int j = k; j < len; j++) {
            arr[get_idx(str[j - k])]--;
            arr[get_idx(str[j])]++;
            tmp = make_string(arr);
            if (m.find(tmp) == m.end())
                m[tmp] = 1;
            else
                m[tmp]++;
            if (m[tmp] > res)
                res = m[tmp];
        }
        cout << res << '\n';
    }
}
