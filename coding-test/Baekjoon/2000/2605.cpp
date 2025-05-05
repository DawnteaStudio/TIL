#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    
    int n, num;
    cin >> n;
    vector<int> vec(n, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> num;
        for (int j = n - 1; j > num; j--)
            vec[j] = vec[j - 1];
        vec[num] = i;
    }
    for (int i = n - 1; i >= 0; i--)
        cout << vec[i] << ' ';
}