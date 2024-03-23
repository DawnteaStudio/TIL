#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct node
{
	node *parent;
	node *left;
	node *right;
	int value;
};

void init_node(int num, node **n, node **current)
{
	(*n)->left = NULL;
	(*n)->right = NULL;
	(*n)->value = num;
	if (num < (*current)->value)
	{
		(*current)->left = (*n);
		(*n)->parent = *current;
		*current = *n;
	}
	else
	{
		while (1)
		{
			if ((*current)->parent == NULL)
			{
                while ((*current)->right != NULL)
                    (*current) = (*current)->right;
				(*current)->right = *n;
				(*n)->parent = (*current);
				*current = *n;
				break;
			}
			else if ((*current)->parent->value > num)
			{
                while ((*current)->right != NULL)
				    (*current) = (*current)->right;
                (*current)->right = *n;
				(*n)->parent = *current;
				*current = *n;
				break;
			}
			else
				*current = (*current)->parent;
		}
	}
}

void	print_node(node *root)
{
	if (root->left != NULL)
		print_node(root->left);
	if (root->right != NULL)
		print_node(root->right);
	cout << root->value << '\n';
}

int main()
{
	fast;
	int num;
	node *current = new node;
	node *root;
	cin >> num;
	current->parent = NULL;
	current->left = NULL;
	current->right = NULL;
	current->value = num;
	root = current;

	while (1)
	{
		cin >> num;
        if (cin.eof())
            break;
		node *n = new node;
		init_node(num, &n, &current);
	}
	print_node(root);
}
