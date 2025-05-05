#include <iostream>
#include <string>
#include <stack>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main() {
    fast;
    string input;
    cin >> input;
    int len = input.length(), res = 0;
    bool fail = false;

    stack<int> s;
    int tmp = 1;
    for (int i = 0; i < len; i++)
    {
        char now = input[i];
        if (now == ')' || now == ']')
        {
            if (s.empty() || (s.top() + now != 43 && s.top() + now != 96))
            {
                fail = true;
                break;
            }
            if (input[i - 1] == '(' || input[i - 1] == '[')
                res += tmp;
            tmp /= s.top();
            s.pop();
        }
        else
        {
            if (now == '(')
            {
                s.push(2);
                tmp *= 2;
            }
            else
            {
                s.push(3);
                tmp *= 3;
            }
        }
    }
    if (fail || !s.empty())
        cout << 0;
    else
        cout << res;
}