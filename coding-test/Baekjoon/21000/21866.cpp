#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int arr[9] = {100, 100, 200, 200, 300, 300, 400, 400, 500};
	int tmp, sum = 0;
	
	for (int i = 0; i < 9; i++) {
	    cin >> tmp;
	    if (tmp > arr[i]) {
	        cout << "hacker";
	        return 0;
	    }
	    sum += tmp;
	}
	if (sum >= 100)
	    cout << "draw";
    else
        cout << "none";
}