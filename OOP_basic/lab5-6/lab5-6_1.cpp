#include<iostream>
using namespace std;

int main() {
	char grade = 'X';
	int score;
	cout << "Enter your score: ";
	cin >> score;

	if (score <= 100 && score >= 0) {
		if (score < 60)
            grade = 'F';
		else if(score < 70)
			grade = 'D';
		else if(score < 80)
			grade = 'C';
		else if(score < 90)
			grade = 'B';
		else
			grade = 'A';
		cout << "Your grade is " << grade << endl;
	}
	else {
		cout << "The score (" << score << ") is invalid" << endl;
	}

	return 0;
}
