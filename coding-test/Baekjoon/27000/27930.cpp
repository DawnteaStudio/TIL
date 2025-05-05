#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string s; cin >> s;

    string yonsei = "YONSEI";
    string korea = "KOREA";
    int y_i = 0;
    int k_i = 0;
    for (int i=0; i<(int)s.size(); i++) {
        if (y_i == (int)yonsei.size()) {
            cout << yonsei;
            break ;
        }
        if (k_i == (int)korea.size())  {
            cout << korea;
            break ;
        }
        if (s[i] == yonsei[y_i]) y_i++;
        if (s[i] == korea[k_i]) k_i++;
    }
    return 0;
}
