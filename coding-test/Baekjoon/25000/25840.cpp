#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, res = 0;
    int arr[13][32] = {0};
    string input;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (arr[stoi(input.substr(0, 2))][stoi(input.substr(3))] == 0)
        {
            arr[stoi(input.substr(0, 2))][stoi(input.substr(3))] = 1;
            res++;
        }
    }
    cout << res;
}
