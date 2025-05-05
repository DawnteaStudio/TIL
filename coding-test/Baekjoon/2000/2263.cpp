#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N;
int inorder[100001];
int postorder[100001];
int i_index[100001];

void make_preorder(int start_in, int end_in, int start_po, int end_po)
{
    if(start_in > end_in || start_po > end_po)
        return ;
    int root = postorder[end_po];
    cout << root << " ";
    int root_index = i_index[root];
    int split = root_index - start_in;

    make_preorder(start_in, root_index - 1, start_po, start_po + split - 1);
    make_preorder(root_index + 1, end_in, start_po + split, end_po -1);
}

int main()
{
    fast;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> inorder[i];
        i_index[inorder[i]] = i;
    }
    for (int i = 1; i <= N; i++)
        cin >> postorder[i];
    make_preorder(1, N, 1, N);

}