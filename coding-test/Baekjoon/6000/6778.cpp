#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    
    int antenna, eyes;
    cin >> antenna >> eyes;

    if (antenna > 6)
    {
        if (eyes <= 4)
            cout << "TroyMartian\n";
    }
    else
    {
        if (antenna > 2)
        {
            if (eyes <= 4)
                cout << "TroyMartian\n";
            if (eyes >= 2)
                cout << "VladSaturnian\n";
        }
        else
        {
            if (eyes < 4)
            {
                if (eyes >= 2)
                    cout << "VladSaturnian\n";
                cout << "GraemeMercurian\n";
            }
        }
    }
}