#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    bool flag;
    string mom, dad;
    cin >> mom >> dad;
    int n;
    cin >> n;

    string baby;
    for (int i = 0; i < n; i++)
    {
        cin >> baby;
        flag = true;
        for (int j = 0; j < 5; j++)
        {
            if ((baby[j] != mom[j * 2] && baby[j] != mom[j * 2 + 1]) || (baby[j] != dad[j * 2] && baby[j] != dad[j * 2 + 1]))
            {
                if (baby[j] >= 'a')
                {
                    cout << "Not their baby!\n";
                    flag = false;
                    break;
                }
                else if (mom[j * 2] >= 'a' && mom[j * 2 + 1] >= 'a' && dad[j * 2 + 1] >= 'a' && dad[j * 2] >= 'a')
                {
                    cout << "Not their baby!\n";
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            cout << "Possible baby.\n";
    }
}
