#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int black = 0, white = 0;
    string input;
    for (int i = 0; i < 8; i++)
    {
        cin >> input;
        for (int j = 0; j < 8; j++)
        {
            if (input[j] == 'P')
                white += 1;
            else if (input[j] == 'N')
                white += 3;
            else if (input[j] == 'B')
                white += 3;
            else if (input[j] == 'R')
                white += 5;
            else if (input[j] == 'Q')
                white += 9;
            else if (input[j] == 'p')
                black += 1;
            else if (input[j] == 'n')
                black += 3;
            else if (input[j] == 'b')
                black += 3;
            else if (input[j] == 'r')
                black += 5;
            else if (input[j] == 'q')
                black += 9;
        }
    }
    cout << white - black;
}