#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main() {
    fast;
    int n, m, res = 1;
    bool end = false;
    cin >> n >> m;

    vector<int> atob(n);
    vector<int> btoa(m);
    for (int i = 0; i < n; i++)
        cin >> atob[i];
    sort(atob.begin(), atob.end(), cmp);
    for (int i = 0; i < m; i++)
        cin >> btoa[i];
    sort(btoa.begin(), btoa.end(), cmp); 

    int indexAtoB = 0, indexBtoA = 0;
    int cntAtoB = 0, cntBtoA = 0;
    int holes = 0;
    while (indexAtoB < n && indexBtoA < m)
    {
        if (holes == 0)
        {
            holes += atob[indexAtoB];
            res--;
            indexAtoB++;
        }
        while (holes && indexBtoA < m)
        {
            res += btoa[indexBtoA];
            holes--;
            indexBtoA++;
        }
    }
    cout << res;
}
