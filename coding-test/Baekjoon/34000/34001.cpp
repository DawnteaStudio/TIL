#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void print_enemy_cnt(int l, int *st) {
	if (l < st[0]) cout << 0;
	else if (l < st[1]) cout << 500;
	else if (l < st[2]) cout << 300;
	else cout << 100;
	cout << ' ';
}

int main()
{
	fast;
	int l; cin >> l;
	int acain_river[] = {200, 210, 220, 225, 230, 235, 245, 250};
	int grandis[] = {260, 265, 270, 275, 280, 285, 290, 295, 300};

	for (int i=0; i<6; i++) print_enemy_cnt(l, &acain_river[i]);
	cout << '\n';
	for (int i=0; i<7; i++) print_enemy_cnt(l, &grandis[i]);
	return (0);
}
