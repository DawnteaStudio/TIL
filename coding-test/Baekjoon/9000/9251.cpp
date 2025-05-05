#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string str1, str2;

    cin >> str1 >> str2;
    int arr[str1.length()][str2.length()];

    for (int i = 0; i < str1.length(); i++)
    {
        for (int j = 0; j < str2.length(); j++)
            arr[i][j] = 0;
    }

    for (int i = 0; i < str1.length(); i++)
    {
        for (int j = 0; j < str2.length(); j++)
        {
            if (str1[i] == str2[j])
            {
                if (i > 0 && j > 0)
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                else
                    arr[i][j] = 1;
            }
            else if (i > 0 && j > 0)
                arr[i][j] = arr[i - 1][j] > arr[i][j - 1] ? arr[i - 1][j] : arr[i][j - 1];
            else if (i > 0)
                arr[i][j] = arr[i - 1][j];
            else if (j > 0)
                arr[i][j] = arr[i][j - 1];
            
            if (i == str1.length() - 1 && j == str2.length() - 1)
                cout << arr[i][j];
        }
    }
}