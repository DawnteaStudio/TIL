#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n;
    cin >> n;

    string input, res;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        int pos = input.find('x');
        if (pos == string::npos)
            pos = input.find('X');
        cin >> input;
        if (input[pos] >= 'a' & input[pos] <= 'z')
            res += input[pos] + ('A' - 'a');
        else
            res += input[pos];
    }
    cout << res;
}
