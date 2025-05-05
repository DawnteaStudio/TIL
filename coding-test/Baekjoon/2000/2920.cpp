#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    bool asce = true, desc = true;
    int tmp = 0, input;
    for (int i = 0; i < 8; i++)
    {
        cin >> input;
        if (tmp != 0)
        {
            if (tmp > input)
            {
                asce = false;
                if (desc == false)
                    break;
            }
            else
            {
                desc = false;
                if (asce == false)
                    break;
            }   
        }
        tmp = input;
    }
    cout << (asce == true ? ("ascending") : desc == true ? "descending" : "mixed");
}
