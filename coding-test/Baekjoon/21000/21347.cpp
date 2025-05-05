#include <iostream>
#include <map>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    string input;
    string output;
    map<char, int> m;

    getline(cin, input);
    getline(cin, output);
    int j = 0;
    for (int i = 0; i < (int)input.length();)
    {
        if (input[i] == output[j])
        {
            if (i == (int)input.length() -1 && j != (int)output.length() - 1)
                m[input[i]] = 1;
            j++;
            i++;
            continue;
        }
        else
        {
            m[input[i - 1]] = 1;
            while (input[i] != output[j])
                j++;
        }
    }
    for (map<char, int>::iterator iter = m.begin(); iter != m.end(); iter++)
        cout << iter->first;
}

// nna
// nnnna