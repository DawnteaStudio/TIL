#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int input;
    cin >> input;

    for (int i = 1; i <= input; i++)
    {
        cout << i << ' ';
        if (i % 6 == 0 || i == input)
            cout << "Go! ";
    }
}
