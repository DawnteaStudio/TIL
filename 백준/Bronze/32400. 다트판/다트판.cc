#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int arr[20];
	for (int i=0; i<20; i++)
        cin >> arr[i];
	double bob = 0, alice = 20;
	for (int i=0; i<20; i++) {
		bob += arr[i];
		if (arr[i] == 20) {
			alice += i + 1 < 20 ? arr[i + 1] : arr[0];
			alice += i - 1 >= 0 ? arr[i - 1] : arr[19];
		}
	}
	bob /= 20.0;
	alice /= 3.0;
	if (bob > alice)
        cout << "Bob";
	else if (bob == alice)
        cout << "Tie";
	else
        cout << "Alice";
}