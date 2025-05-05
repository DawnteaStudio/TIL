#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, time, yungsik=0, minsik=0; cin >> n;
	for (int i=0; i<n; i++) {
		cin >> time;
		yungsik += (time / 30 + 1) * 10;
		minsik += (time / 60 + 1) * 15;
	}
	if (yungsik == minsik) cout << "Y M " << yungsik;
	else if (yungsik < minsik) cout << "Y " << yungsik;
	else cout << "M " << minsik;
}
