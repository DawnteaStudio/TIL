#include <iostream>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, input;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int res = 0;
        cin >> input;
        queue<int> q;
        for (int j = 1; j <= 3; j++)
            q.push(j);
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            if (top == input)
                res++;
            else
            {
                for (int j = 1; j <= 3; j++)
                {
                    if (top + j < input)
                        q.push(top + j);
                    else if (top + j == input)
                        res++;
                }
            }
        }
        cout << res << '\n';
    }
}
