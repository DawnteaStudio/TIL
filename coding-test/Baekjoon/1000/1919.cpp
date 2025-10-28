#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dat_a[26];
int dat_b[26];

int main()
{
    fast;

    string a, b;
    cin >> a >> b;

    int len_a = a.length();
    int len_b = b.length();
    for (int i = 0; i < len_a; i++)
        dat_a[a[i] - 'a']++;
    for (int i = 0; i < len_b; i++)
        dat_b[b[i] - 'a']++;
    
    int res = 0;
    for (int i = 0; i < 26; i++) {
        int tmp = dat_a[i] - dat_b[i];
        if (tmp < 0)
            tmp *= -1;
        res += tmp;
    }
    cout << res;
}
