#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, idx;
    cin >> n >> idx;
    
    vector<string> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    
    sort(vec.begin(), vec.end());
    cout << vec[idx - 1];
}
