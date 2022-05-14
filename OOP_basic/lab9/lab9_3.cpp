#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	bool check = false;
		cout << "Please enter a number: ";
		cin >> n;
		if (n < 2){
            cout << "Wrong number!!!" << endl;
			return 0;
        }

        cout << "Size of random array: " << n/2 << endl;
        cout << "[ Array ]" << endl;
		int *list;
		list = new int[n/2];
		cout << n/2 << endl;
		for (int i = 0; i < n/2; i++)
			list[i] = rand() % n + 1;

		for (int i = 0; i < n/2; i++) {
				cout << list[i] << " ";
			}
			cout << endl;
		while (1){
			for (int i = 0; i < n/2; i++) {
				for (int j = i+1; j < n/2; j++) {
					if (list[i] == list[j]){
						cout << "Duplicates found." << endl;
						check = true;
						break;
					}
				if (check)
				break;
				}
		}	if (!check)
				cout << "Duplicates not found." << endl;
			break;
		
		}

		delete[] list;		

	return 0;
}
