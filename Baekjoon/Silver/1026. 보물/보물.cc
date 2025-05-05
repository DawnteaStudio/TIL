#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int num, res = 0;
    cin >> num;
    int arr1[num];
    int arr2[num];

    for (int i = 0; i < num; i++)
        cin >> arr1[i];
    for (int i = 0; i < num; i++)
        cin >> arr2[i];
    sort(arr1, arr1+num);
    sort(arr2, arr2+num);
    for (int i = 0; i < num; i++)
        res += (arr1[i] * arr2[num - i - 1]);
    cout << res;
}
