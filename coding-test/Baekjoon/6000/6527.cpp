#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int get_g(int a, int b)
{
    int tmp;
    if (a == 1 || b == 1)
        return 1;

    while (a != 0 && b != 0)
    {
        tmp = max(a, b);
        a = min(a, b);
        b = tmp % a;
    }
    return max(a, b);
}

void make_word(string &input, vector<string> &vec)
{
    string res;
    int size = input.length();
    for (int i = 0; i < size; i++) {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {
            if (input[i] >= 'A' && input[i] <= 'Z')
                res += input[i] + 32;
            else
                res += input[i];
        }
        else {
            if (!res.empty()) {
                if (find(vec.begin(), vec.end(), res) == vec.end())
                    vec.push_back(res);
            }
            res = "";
        }
    }
    if (!res.empty())
        if (find(vec.begin(), vec.end(), res) == vec.end())
            vec.push_back(res);
}

int main()
{
    fast;
    int words = 0, games = 0;
    string input;
    vector<string> vec;
    while (cin >> input) {
        if (input == "BULLSHIT") {
            games++;
            words += vec.size();
            vec.clear();
        }
        else
            make_word(input, vec);
    }
    int G = get_g(words, games);
    cout << (words / G) << " / " << (games / G);
}