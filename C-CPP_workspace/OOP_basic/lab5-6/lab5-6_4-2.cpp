#include<iostream>
using namespace std;

int main() {
	int num;
	do {
        cout << "Enter the number (0, 10]: ";
		cin >> num;
	} while (num > 10 && num <= 0); //반드시 세미콜론 찍어줌
	cout << "Success!" << endl;
	return 0;
}
