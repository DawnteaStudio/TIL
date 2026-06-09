#include <iostream>
#include <string>
#include <vector>
using namespace std;

int inputGrade(float grade) {
	cin >> grade;
	if ((grade - (int)grade) != 0.0 || grade < 0 || grade > 100) {
		cout << "invalid input!!!" << endl;
		exit(EXIT_FAILURE);
	}
	else
		return (int)grade;
}
int topGrade(const vector<int>& grade) {
    int greatest;
    for(int i = 0; i < grade.size()-1; i++){
        if(grade[i] > grade[i+1]){
            greatest = grade[i];
        }
        else
            greatest = grade[i+1];
    }
        return greatest;
    }

int main() {
	vector<int> grades;
	float _grade = 0;
	for(int i = 0; i < 3; i++) {
		cout << "Input " << i << "-th grade(0~100):";
		int grade = inputGrade(_grade);
		grades.push_back(grade);
}
	/* 구현 */
	cout << "Top Grade: " << topGrade(grades)<<endl;
	return 0;
}
