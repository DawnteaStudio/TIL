#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int n, m;
	cout << "Enter n for n x m matrix: ";
	cin >> n;
	cout << "Enter m for n x m matrix: ";
	cin >> m;

	for(int row = 1; row <= n; row++){
        for(int col = 1; col <= m; col++){
            cout << setw(4) << row*col;
        }
        cout << endl;
    }
	return 0;
}
