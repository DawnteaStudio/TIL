#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<string> vec;

int main() {

    for (char a = '1'; a <= '9'; a++) {
        for (char b = '1'; b <= '9'; b++) {
            if (a == b)
                continue;
            for (char c = '1'; c <= '9'; c++) {
                if (c != a && c != b) {
                    string res = "";
                    res += a;
                    res += b;
                    res += c;
                    vec.push_back(res);
                }
            }
        }
    }
    cin >> n;
    string tmp;
    int s, b;
    for (int i = 0; i < n; i++) {
        cin >> tmp >> s >> b;
        int size = vec.size();

        vector<string> filter;
        for (int j = 0; j < size; j++) {
            int tmp_s = 0, tmp_b = 0;
            for (int p = 0; p < 3; p++) {
                if (tmp[p] == vec[j][p])
                    tmp_s++;
                for (int q = 0; q < 3; q++) {
                    if (q == p)
                        continue;
                    if (tmp[p] == vec[j][q])
                        tmp_b++;
                }
            }
            if (tmp_s == s && tmp_b == b)
                filter.push_back(vec[j]);
        }
        vec = filter;
    }

    // Please write your code here.
    cout << vec.size();
    return 0;
}