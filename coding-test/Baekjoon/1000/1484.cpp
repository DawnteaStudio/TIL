#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    vector <int> vec;
    cin >> n;

    for (int i = 2; i < n; i++)
    {
        for (int j = i - 1; j > 0; j--)
        {
            if ((i + j) * (i - j) > n)
                break;
            else if ((i + j) * (i - j) == n)
                vec.push_back(i);
        }
    }
    if (vec.empty())
        cout << -1;
    else
    {
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << '\n';
    }
}