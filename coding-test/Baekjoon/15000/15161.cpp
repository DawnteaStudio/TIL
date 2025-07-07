#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int k;
    cin >> k;
    int arr[11][11];
    for (int j = 1; j <= 10; j++)
    {
        for (int h = 1; h <= 10; h++)
            arr[j][h] = 1;
    }
    int row, col;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> row;
            for (int h = 1; h <= 10; h++)
                arr[row][h] = 0;
        }
        for (int j = 0; j < 3; j++)
        {
            cin >> col;
            for (int h = 1; h <= 10; h++)
                arr[h][col] = 0;
        }
        for (int j = 1; j <= 10; j++)
        {
            for (int h = 1; h <= 10; h++)
                arr[j][h]++;
        }
    }
    for (int j = 1; j <= 10; j++)
    {
        for (int h = 1; h <= 10; h++)
            cout << arr[j][h] << ' ';
        cout << '\n';
    }
}