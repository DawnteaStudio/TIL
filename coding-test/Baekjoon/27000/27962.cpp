#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int N, size = 1, cnt = 0;
    string str, str_a, str_b;
    cin >> N >> str;

    while (size < N)
    {
        cnt = 0;
        str_a = str.substr(0, size);
        str_b = str.substr(N - size, size);

        for (int i = 0; i < size; i++)
        {
            if (str_a[i] != str_b[i])
                cnt++;
        }
        if (cnt == 1)
        {
            cout << "YES";
            return (0);
        }
        size++;
    }
    cout << "NO";
    return (0);
}
