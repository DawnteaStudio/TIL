#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int res;

struct node
{
    int parent;
    vector<int> childs;
};

void get_res(node *nd, vector<node> &vec)
{
    if (nd->childs.empty())
        res++;
    else
    {
        for (int i = 0; i < nd->childs.size(); i++)
            get_res(&vec[nd->childs[i]], vec);
    }
}

int main() {
    fast;
    int n, num, del;
    cin >> n;
    vector<node> vec(n);
    node *root;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        vec[i].parent = num;
        if (num == -1)
            root = &vec[i];
        else
            vec[num].childs.push_back(i);
    }
    cin >> del;
    if (root->parent == vec[del].parent)
    {
        cout << 0;
        return 0;
    }
    auto it = find(vec[vec[del].parent].childs.begin(), vec[vec[del].parent].childs.end(), del);
    vec[vec[del].parent].childs.erase(it);
    get_res(root, vec);
    cout << res;
}
