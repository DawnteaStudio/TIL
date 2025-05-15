#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

#define DOWN_RANGE_CORRECTION(a) (a < 0 ? a + 4 : a)
#define UP_RANGE_CORRECTION(a) (a > 3 ? a - 4 : a)

struct MinRotation {
	int cnt;
	double value;
};

int main()
{
	fast;
	int arr[4];

	cin >> arr[0] >> arr[1] >> arr[3] >> arr[2];

	MinRotation result = {4, 0};
	int target1 = 0, target2 = 1;
	for (int i=0; i<4; i++) {
		int fixed_target1 = DOWN_RANGE_CORRECTION(target1 - i);
		int fixed_target2 = DOWN_RANGE_CORRECTION(target2 - i);

		double tmp = (double)arr[fixed_target1] / arr[UP_RANGE_CORRECTION(fixed_target1 + 2)] + (double)arr[fixed_target2] / arr[UP_RANGE_CORRECTION(fixed_target2 + 2)];
		if (result.cnt == 4 || result.value < tmp) {
			result.cnt = i;
			result.value = tmp;
		}
	}
	cout << result.cnt;
}