#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;

    string input;
    int R, C, errR, errC, printR, printC;
    cin >> R >> C;

    char arr[R][C];

    for (int i = 0; i < R; i++)
    {
        cin >> input;
        for (int j = 0; j < C; j++)
            arr[i][j] = input[j];
    }
    cin >> errR >> errC;

    for (int i = 0; i < 2 * R; i++)
    {
        printR = i;
        for (int j = 0; j < 2 * C; j++)
        {
            printC = j;
            if (i >= R)
                printR = 2 * R - i - 1;
            if (j >= C)
                printC = 2 * C - j - 1;
            if (i == errR - 1 && j == errC - 1)
            {
                if (arr[printR][printC] == '#')
                    cout << '.';
                else
                    cout << '#';
            }
            else
                cout << arr[printR][printC];
        }
        cout << '\n';
    }
}
