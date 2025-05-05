#include <iostream>
#include <deque>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, tmp;
    char input;
    cin >> n;

    deque<char> vec_f;
    deque<char> vec_b;
    deque<bool> del;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp == 1)
        {
            cin >> input;
            vec_b.push_back(input);
            del.push_back(false);
        }
        else if (tmp == 2)
        {
            cin >> input;
            vec_f.push_back(input);
            del.push_back(true);
        }
        else
        {
            if (!del.empty())
            {
                if (del.back() == true)
                    vec_f.pop_back();
                else
                    vec_b.pop_back();
                del.pop_back();
            };
        }
    }
    int f_size = vec_f.size();
    int b_size = vec_b.size();
    if (f_size == 0 && b_size == 0)
        cout << 0;
    else
    {
        for (int i = f_size - 1; i >= 0; i--)
            cout <<vec_f[i];
        for (int i = 0; i < b_size; i++)
            cout << vec_b[i];
    }
}