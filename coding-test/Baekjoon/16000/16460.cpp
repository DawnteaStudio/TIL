#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string str, sex, s;
    vector<string> vec;
    int limit, d;
    cin >> str >> sex >> limit;
    int len = sex.length();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str >> s >> d;
        if (s.length() != len || sex == s) {
            if (limit >= d)
                vec.push_back(str);
        }
    }
    sort(vec.begin(), vec.end());

    int size = vec.size();
    if (size == 0)
        cout << "No one yet";
    for (int i = 0; i < size; i++)
        cout << vec[i] << '\n';
}
