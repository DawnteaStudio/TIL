#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_date(int sun, int ys, int moon, int ym)
{
    int cnt = sun < moon ? sun : moon;

    sun -= cnt; moon -= cnt;
    if (sun == 0) {
        for (int i=0;;i+=ys) {
            cnt = i;
            if ((i - moon) % ym == 0) break ;
        }
    }
    else {
        for (int i=0;;i+=ym) {
            cnt += i;
            if ((sun + i) % ys == 0) break ;
        }
    }
    return (cnt);
}

int main()
{
    fast;
    int ds, ys, dm, ym;

    cin >> ds >> ys >> dm >> ym;
    cout << find_date(ys - ds, ys, ym - dm, ym);
    return (0);
}