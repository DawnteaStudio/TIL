#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int a, b, c, hypo, line1, line2;
    cin >> a >> b >> c;
    while (a != 0)
    {
        if (a > b)
        {
            line1 = b;
            if (a > c)
            {
                line2 = c;
                hypo = a;
            }
            else
            {
                line2 = a;
                hypo = c;
            }
        }
        else
        {
            line1 = a;
            if (b > c)
            {
                line2 = c;
                hypo = b;
            }
            else
            {
                line2 = b;
                hypo = c;
            }
        }
        if (hypo * hypo == line1 * line1 + line2 * line2)
            cout << "right\n";
        else
            cout << "wrong\n";
        cin >> a >> b >> c;
    }
}
