#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int get_res(int &c)
{
    int tmp = 0;

    if (c != 0)
    {
        tmp += c / 3;
        c %= 3;
    }
    return tmp;
}

int main ()
{
    fast;
    int r, g, b;
    cin >> r >> g >> b;

    int res = (r > g) ? ((g > b) ? b : g) : ((r > b) ? b : r);
    
    r -= res;
    g -= res;
    b -= res;

    res += get_res(r);
    res += get_res(g);
    res += get_res(b);

    int tmp = (r > g) ? ((r > b) ? r : b) : ((g > b) ? g : b);
    int tmp2 = r + g + b;
    
    if (tmp && tmp2 == tmp) {
        res++;
    }
    else if (tmp) {
        res += tmp;
    }
    cout << res;
}