#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool check_range(int *range, double value) {
	return (double)range[0] <= value && (double)range[1] >= value;
}

bool is_real_purple(int *h, int *s, int *v, int R, int G, int B) {
	int M = max(max(R, G), B), m = min(min(R, G), B);        
	if (!check_range(v, M))
        return false;

	double S = 255 * (double)(M - m) / M;
	if (!check_range(s, S))
        return false;

	double H;
	if (M == R)
        H = (double)60 * (G - B) / (M - m);
	else if (M == G)
        H = 120 + (double)60 * (B - R) / (M - m);
	else
        H = 240 + (double)60 * (R - G) / (M - m);
	if (H < 0.0)
        H += 360;
	if (!check_range(h, H))
        return false;
	return true;
}

int main()
{
	fast;
	int h[2], s[2], v[2], R, G, B;
	cin >> h[0] >> h[1] >> s[0] >> s[1] >> v[0] >> v[1] >> R >> G >> B;
	if (is_real_purple(h, s, v, R, G, B)) cout << "Lumi will like it.";
	else cout << "Lumi will not like it.";
}