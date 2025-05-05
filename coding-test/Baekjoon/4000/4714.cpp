#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    double input;
    cout.precision(2);
    cout << fixed;
    while (true)
    {
        cin >> input;
        if (input < 0)
            break;
        cout << "Objects weighing " << input <<" on Earth will weigh " << input * 0.167 << " on the moon.\n";
    }
}
