#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int arr[26] = {0}, max_value = 0;
    int tmp;
    char res = '?';
    fast;
    string str;
    cin >> str;

    for (int i = 0; i < (int)str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            tmp = str[i] - 'a';
        else
            tmp = str[i] - 'A';
        arr[tmp]++;
        if (arr[tmp] > max_value)
        {
            max_value = arr[tmp];
            if (str[i] >= 'a')
                res = str[i] - 'a' + 'A';
            else
                res = str[i];
        }
        else if (arr[tmp] == max_value)
            res = '?';
    }
    cout << res;
}
