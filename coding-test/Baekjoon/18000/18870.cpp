#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct node
{
    int num;
    int res;
};

bool cmp(node *a, node *b)
{
    return a->num < b->num;
}

int main() {
    fast;
    int n, input, res = 0;
    cin >> n;
    vector<node> v(n);
    vector<node *> sorted(n);

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v[i].num = input;
        sorted[i] = &v[i];
    }
    sort(sorted.begin(), sorted.end(), cmp);
    sorted[0]->res = 0;
    for (int i = 1; i < n; i++)
    {
        if (sorted[i]->num == sorted[i - 1]->num)
            sorted[i]->res = res;
        else
        {
            res++;
            sorted[i]->res = res;
        }
    }
    for (int i = 0; i < n; i++)
        cout << v[i].res << " ";
}
