#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    string arr[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cin >> arr[i][j];
    }
    
    for (int i = 0; i < 10; i++)
    {
        string tmp;
        tmp = arr[i][0];
        for (int j = 1; j < 10; j++)
        {
            if (tmp != arr[i][j])
                break;
            if (j == 9)
            {
                cout << 1;
                return (0);
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        string tmp;
        tmp = arr[0][i];
        for (int j = 1; j < 10; j++)
        {
            if (tmp != arr[j][i])
                break;
            if (j == 9)
            {
                cout << 1;
                return (0);
            }
        }
    }
    cout << 0;
}