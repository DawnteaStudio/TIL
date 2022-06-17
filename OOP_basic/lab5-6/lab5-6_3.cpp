#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int column = 1, row = 1;
	while (row <= 10) {
		while (column <= 10) {
			int num;
			if(row == column)
                num = 1;
            else
                num = 0;
			cout << setw(4) << num;
			column++;
		}
		cout << endl;
        column = 1;
		row++;
	}
	return 0;
}
