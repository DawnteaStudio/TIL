#include <iostream>
#include<algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, w, h, l;
    cin >> n >> w >> h >> l;
    
    int tmp = (w / l) * (h / l);
    if (tmp > n)
        cout << n;
    else
        cout << tmp;
}
