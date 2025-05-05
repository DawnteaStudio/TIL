#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, seq, num;
    cin >> n;
    cout << n << '\n';

    for (int i = 0; i < n; i++)
    {
        cin >> seq;
        cout << seq << '\n';
        vector<int> vec;
        for (int j = 0; j < seq; j++)
        {
            cin >> num;
            vec.push_back(num);
        }
        sort(vec.begin(), vec.end());
        for (int j = 1; j < seq; j++)
            cout << vec[j] << " ";
        cout << vec[0] << '\n';
    }
}