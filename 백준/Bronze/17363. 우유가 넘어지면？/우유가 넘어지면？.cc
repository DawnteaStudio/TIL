#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

char    change_char(char ch)
{
    char res;

    switch (ch)
    {
        case '-':
            res = '|';
            break;
        case '|':
            res = '-';
            break;
        case '\\':
            res = '/';
            break;
        case '/':
            res = '\\';
            break;
        case '^':
            res = '<';
            break;
        case '<':
            res = 'v';
            break;
        case 'v':
            res = '>';
            break;
        case '>':
            res = '^';
            break;
        default:
            res = ch;
            break;
    }
    return res;
}

int main(void)
{
    fast;
    int h, w;
    cin >> h >> w;
    string arr[h];
    for (int i = 0; i < h; i++)
        cin >> arr[i];
    for (int i = w - 1; i >= 0; i--)
    {
        for (int j = 0; j < h; j++)
            cout << change_char(arr[j][i]);
        cout << '\n';
    }
}