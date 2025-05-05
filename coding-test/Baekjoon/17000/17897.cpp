#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, res;
    int incld[2] = {0};
    string input, ans;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> res;
        cin.ignore();
        getline(cin, ans);
        incld[0] = 0;
        incld[1] = 0;
        for (int j = 0; j < res; j++)
        {
            getline(cin, input);
            if (input == "pancakes")
                incld[0] = 1;
            else if (input == "pea soup")
                incld[1] = 1;
        }
        if (incld[0] == 1 && incld[1] == 1)
        {
            cout << ans;
            return 0;
        }
    }
    cout << "Anywhere is fine I guess";
}