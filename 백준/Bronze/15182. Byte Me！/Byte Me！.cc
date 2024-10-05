#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<int> vecRow(iN + 1, 0);
	vector<int> vecCol(8, 0);

	for (int i = 0; i <= iN; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			int iNum;
			cin >> iNum;
			vecRow[i] ^= iNum;
			vecCol[j] ^= iNum;
		}
	}

	bool bEven = false;
	int iEven = 0;
	int iOdd = 0;
	for (int i = 0; i < iN; ++i)
	{
		if (vecRow[i] % 2 == 0)
		{
			++iEven;
		}
		else
		{
			++iOdd;
		}
	}
	bEven = (iEven > iOdd ? true : false);

	int iByte = -1;
	int iBit = -1;

	if (bEven)
	{
		cout << "Even" << "\n";
		for (int i = 0; i < iN; ++i) if (vecRow[i] % 2 == 1) iByte = i + 1;
		for (int i = 0; i < 8; ++i) if (vecCol[i] % 2 == 1) iBit = i + 1;
	}
	else
	{
		cout << "Odd" << "\n";
		for (int i = 0; i < iN; ++i) if (vecRow[i] % 2 == 0) iByte = i + 1;
		for (int i = 0; i < 8; ++i) if (vecCol[i] % 2 == 0) iBit = i + 1;
	}

	cout << "Byte " << iByte << " is broken\n";
	cout << "Bit " << iBit << " is broken\n";
	return 0;
}