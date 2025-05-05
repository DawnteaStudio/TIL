#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, max = 0, i = 1;
    int res;
    while (i <= 9)
    {
        cin >> input;
        if (max < input)
        {
            max = input;
            res = i;
        }
        i++;
    }
    cout << max << '\n' << res;
}
