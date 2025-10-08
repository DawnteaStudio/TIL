#include <iostream>
#include <string>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

map<string, string> mp = {
    {"A",".-"}, {"B" , "-..."}, {"C" , "-.-."}, {"D" , "-.."}, {"E" , "."},
    {"F" , "..-."}, {"G" , "--."}, {"H" , "...."}, {"I" , ".."}, {"J" , ".---"},
    {"K" , "-.-"}, {"L" , ".-.."}, {"M" , "--"}, {"N" , "-."}, {"O" , "---"},
    {"P" , ".--."}, {"Q" , "--.-"}, {"R" , ".-."}, {"S" , "..."}, {"T" , "-"},
    {"U" , "..-"}, {"V" , "...-"}, {"W" , ".--"}, {"X" , "-..-"}, {"Y" , "-.--"},
    {"Z" , "--.."}, {"0" , "-----"}, {"1" , ".----"}, {"2" , "..---"}, {"3" , "...--"},
    {"4" , "....-"}, {"5" , "....."}, {"6" , "-...."}, {"7" , "--..."}, {"8" , "---.."},
    {"9" , "----."}
};

int main() {
    fast;

    string s;
    getline(cin, s);
    string mos;

    int len = s.length();
    for (int i = 0; i < len; i++) {
        string tmp = " ";
        if (s[i] >= 'a' && s[i] <= 'z') {
            tmp[0] = (char)(s[i] - 'a' + 'A');
        }
        else
            tmp[0] = s[i];
        if (mp.find(tmp) != mp.end())
            mos += mp[tmp];
        else
            continue;
    }
    len = mos.length();
    if (len == 0) {
        cout << "NO";
        return 0;
    }
    int start = 0, end = len - 1;
    while (start <= end) {
        if (mos[start] != mos[end]) {
            cout << "NO";
            break;
        }
        start++;
        end--;
    }
    if (start > end)
        cout << "YES";
}
