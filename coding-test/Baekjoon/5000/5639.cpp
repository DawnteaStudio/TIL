#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct node
{
    int value;
    node *parent;
    node *left;
    node *right;
};

void    print_tree(node &tree)
{
    if (tree.left)
        print_tree(*tree.left);
    if (tree.right)
        print_tree(*tree.right);
    cout << tree.value << '\n';
}

int main() {
    fast;
    node tree;
    cin >> tree.value;
    tree.left = nullptr;
    tree.right = nullptr;
    tree.parent = nullptr;
    node *now = &tree;

    int criteria = tree.value;
    while (1)
    {
        node *tmp;
        tmp = new node;
        cin >> tmp->value;
        if (cin.eof())
            break;
        tmp->left = nullptr;
        tmp->right = nullptr;
        tmp->parent = nullptr;

        if (now->value > tmp->value)
        {
            now->left = tmp;
            tmp->parent = now;
            now = tmp;
        }
        else
        {
            while (1)
            {
                if (now->parent == nullptr)
                {
                    while (now->right != nullptr)
                        now = now->right;
                    now->right = tmp;
                    tmp->parent = now;
                    now = tmp;
                    break;
                }
                else if (now->parent->value > tmp->value)
                {
                    while (now->right != nullptr)
                        now = now->right;
                    now->right = tmp;
                    tmp->parent = now;
                    now = tmp;
                    break;
                }
                else
                    now = now->parent;
            }
        }
    }
    print_tree(tree);
}
