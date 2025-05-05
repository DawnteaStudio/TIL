#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct fib
{
    int index;
    int num;
    int val;
    bool is_start;
};


void    find_value(fib *f)
{
    int tmp;
    f->val = 1;
    tmp = f->index;
    tmp -= f->val;
    while (tmp > 0)
    {
        f->val++;
        tmp -= f->val;
    }
    f->num = f->val;
    if (f->is_start)
        f->val += f->val * (tmp * -1);
    else
        f->val = (f->val * f->val) - (f->val * (tmp * -1));
}

int main()
{
    fast;
    fib start, end;
    int res = 0;
    cin >> start.index >> end.index;
    start.is_start = true;
    end.is_start = false;
    find_value(&start);
    find_value(&end);

    for (int i = start.num + 1; i < end.num; i++)
        res += i * i;
    if (start.num != end.num)
        res += (start.val + end.val);
    else
        res += start.num * (end.index - start.index + 1);
    cout << res;
}
