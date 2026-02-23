#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void swap(int *arr, int a, int b) {
	long long sum = 0;
	for (int i=a; i<=b; i++)
        sum += arr[i];
	cout << sum << '\n';

	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void sub(int *arr, int a, int b, int c, int d) {
	long long sum1 = 0, sum2 = 0;
	for (int i=a; i<=b; i++)
        sum1 += arr[i];
	for (int i=c; i<=d; i++)
        sum2 += arr[i];
	cout << sum1 - sum2 << '\n';
}

int main()
{
	fast;
	int n, q;
    cin >> n >> q;
	int arr[1010];
	for (int i=1; i<=n; i++)
        cin >> arr[i];
	int cmd, a, b, c, d;
	for (int i=0; i<q; i++) {
		cin >> cmd >> a >> b;
		if (cmd == 1)
            swap(arr, a, b);
		else {
			cin >> c >> d;
			sub(arr, a, b, c, d);
		}
	}
}