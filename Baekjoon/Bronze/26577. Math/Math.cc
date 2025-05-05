#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct node
{
	char flag;
	int left;
	node *right;
};


int main()
{
	fast;
	int n, value;
	string str, tmp;
	char flag;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		node head;
		head.right = nullptr;
		node *now = &head;
		getline(cin, str);
		stringstream ss(str);
		while (ss >> tmp) {
			if (tmp.length() == 1 && (tmp[0] < '0' || tmp[0] > '9')) {
				if (tmp[0] == '*') {
					ss >> tmp;
					value *= stoi(tmp);
				}
				else if (tmp[0] == '/') {
					ss >> tmp;
					value /= stoi(tmp);
				}
				else if (tmp[0] == '%') {
					ss >> tmp;
					value %= stoi(tmp);
				}
				else {
					now->flag = tmp[0];
					now->left = value;
					now->right = new node;
					now = now->right;
					now->right = nullptr;
				}
			}
			else
				value = stoi(tmp);
		}
		now->left = value;
		int res = head.left;
		while (head.right != nullptr) {
			if (head.flag == '+')
				res += head.right->left;
			else
				res -= head.right->left;
			head = *head.right;
		}
		cout << res << '\n';
	}
}