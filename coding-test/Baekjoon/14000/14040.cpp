#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int max_len = 1;

void find_palindrome(string str, int start, int size)
{
    int max_size = min(start - 0, size - start - 1);
    int left, right;
    int cnt = 2;

    if (str[start + 1] == str[start - 1])
    {
        cnt = 1;
        left = start;
        right = start;
    }
    else if (str[start] == str[start - 1])
    {
        left = start - 1;
        right = start;
    }
    else if (str[start] == str[start + 1])
    {
        left = start;
        right = start + 1;
    }
    else
        return;

    for (int i = 1; i <= max_size; i++)
    {
        if (str[right + i] == str[left - i])
            cnt += 2;
        else
            break;
    }
    max_len = max(max_len, cnt);
}

int main()
{
    fast;
    string str;
    cin >> str;

    int size = (int)str.size();
    for (int i = 1; i < size - 1; i++)
        find_palindrome(str, i, size);
    cout << max_len;
    return (0);
}
