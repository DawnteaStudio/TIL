#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int getG(int a, int b)
{
    int tmp;
    while (b != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {
    fast;
    int n, G, tmp, pos;
    bool flag;
    vector<int> vec;
    cin >> n;

    int M, N, x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> M >> N >> x >> y;
        flag = true;
        pos = 0;
        vec.clear();
        G = (M * N) / getG(max(M, N), min(M, N));
        
        for (tmp = x; tmp <= G; tmp += M)
            vec.push_back(tmp);
        for (tmp = y; tmp <= G; tmp += N)
        {
            while (pos < vec.size() && vec[pos] < tmp)
                pos++;
            if (pos < vec.size() && tmp == vec[pos])
            {
                cout << tmp << '\n';
                flag = false;
                break;
            }
        }
        if (flag)
            cout << -1 << '\n';
    }


}
