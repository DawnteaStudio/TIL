#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct Node
{
    int v;
    Node *left;
    Node *right;
};

void add_Node(Node *node, int v)
{
    Node *tmp = new Node;
    Node *now = node;
    while (now->right) {
        now = now->right;
    }
    now->right = tmp;
    tmp->left = now;
    tmp->right = nullptr;
    tmp->v = v;
}

void link(Node *node)
{
    Node *now = node;
    while (now->right) {
        now = now->right;
    }

    node->left = now;
    now->right = node;
}

int remove_Node(Node **node, int idx)
{
    Node *now = *node;
    int cnt = 1;
    while (cnt < idx) {
        now = now->right;
        cnt++;
    }
    int res = now->v;
    now->left->right = now->right;
    now->right->left = now->left;
    *node = now->right;
    free(now);
    return res;
}

int main()
{
    fast;
    int n, k;
    cin >> n >> k;
    Node *head = new Node;
    head->v = 1;
    head->left = nullptr;
    head->right = nullptr;
    for (int i = 2; i <= n; i++)
        add_Node(head, i);
    link(head);
    cout << "<";
    for (int i = 0; i < n; i++) {
        cout << remove_Node(&head, k);
        if (i != n - 1)
            cout << ", ";
    }
    cout << ">";
}
