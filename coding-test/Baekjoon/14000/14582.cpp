#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    bool flag = false;
    int s1 = 0, s2 = 0;
    int arr1[9];
    int arr2[9];
    for (int i = 0; i < 9; i++)
        cin >> arr1[i];
    for (int i = 0; i < 9; i++)
        cin >> arr2[i];

    for (int i = 0; i < 9; i++) {
        s1 += arr1[i];
        if (s1 > s2)
            flag = true;
        s2 += arr2[i];
    }
    if (flag && s2 > s1)
        cout << "Yes";
    else
        cout << "No";
}