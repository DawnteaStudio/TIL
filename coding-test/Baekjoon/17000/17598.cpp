#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string str;
    int arr[2] = {0,};
    for (int i=0; i<9; i++) {
        cin >> str;
        if (str == "Tiger") arr[0]++;
        else arr[1]++;
    }
    if (arr[0] > arr[1]) cout << "Tiger";
    else cout << "Lion";
}