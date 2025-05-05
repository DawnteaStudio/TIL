#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

string make_str(int h, int m, int diff_h, int diff_m)
{
    string res;
    int tmp_h, tmp_m;
    tmp_h = h + diff_h;
    if (tmp_h <= 0)
        tmp_h = 24 + tmp_h;
    tmp_m = m + diff_m;
    if (tmp_m >= 60) {
        tmp_m -= 60;
        tmp_h++;
    }
    if (tmp_h >= 24)
        tmp_h -= 24;
    if (tmp_m < 10)
        res = to_string(tmp_h) + "0" + to_string(tmp_m);
    else
        res = to_string(tmp_h) + to_string(tmp_m);
    if (res[0] == '0')
        res = res.substr(1); 
    return res;
}

int main()
{
    fast;
    string str;
    string arr[6];
    cin >> str;
    string backup = str;
    int h, m;
    if (str.length() == 4) {
        h = stoi(str.substr(0, 2));
        str = str.substr(2);
    }
    else if (str.length() == 3) {
        h = stoi(str.substr(0, 1));
        str = str.substr(1);
    }
    else if (str.length() <= 2)
        h = 0;
    m = stoi(str);

    cout << backup << " in Ottawa\n";
    cout << make_str(h, m, -3, 0) << " in Victoria\n";
    cout << make_str(h, m, -2, 0) << " in Edmonton\n";
    cout << make_str(h, m, -1, 0) << " in Winnipeg\n";
    cout << backup << " in Toronto\n";
    cout << make_str(h, m, 1, 0) << " in Halifax\n";
    cout << make_str(h, m, 1, 30) << " in St. John's\n";
}
