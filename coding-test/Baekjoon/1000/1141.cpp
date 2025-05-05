#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    string tmp;
    cin >> n;
    int res = n;
    string arr[50];
    bool deleted[50] = {false};

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || deleted[i] == true || deleted[j] == true)
                continue;
            for (int k = 0; k < (int)arr[i].length(); k++)
            {
                if (k > (int)arr[j].length() || arr[j][k] != arr[i][k])
                    break;
                if (k == (int)arr[i].length() - 1)
                {
                    if (arr[j].length() < arr[i].length())
                        deleted[j] = true;
                    else
                        deleted[i] = true;
                    res--;
                }
            }
        }
    }
    cout << res;
}