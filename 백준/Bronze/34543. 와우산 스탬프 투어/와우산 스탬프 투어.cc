#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int n, step;
	cin >> n >> step;

	int score = 0;
	score += n * 10;
	if (n >= 3)
		score += 20;
	if (n == 5)
		score += 50;
	if (step > 1000)
		score -= 15;
	if (score < 0)
		score = 0;
	cout << score;
}