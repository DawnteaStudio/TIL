#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Student{
    private:
        string name;
        int number;
        string major;
        vector<string> lecture;
        vector<char> grade;
    public:
        Student(string _name, int _number, string _major) :
            name(_name), number(_number), major(_major) {}
        Student() :
            name("default"), number(0), major("depart") {}
        void setName(string _name) {
            name = _name;
        }
        void setID(int _number) {
            number = _number;
        }
        void setDpt(string _major) {
            major = _major;
        }

        void print(){
            cout<<name<<" "<< number << " " << major<<endl;
        }

        void addGrade(string _lecture, char _grade) {
            lecture.push_back(_lecture);
            grade.push_back(_grade);
        }

        void printGrades() {
            int size = lecture.size();
            for (int i = 0; i < size; i++) {
                cout << lecture[i] << " " << grade[i] << endl;
            }
            getGPA();
        }

        void getGPA() {
            int size = grade.size();
            float sum = 0, gpa;
            for (int i = 0; i < size; i++) {
                if (grade[i] < 69 && grade[i] > 64)
                    sum += 69 - grade[i];
            }
            gpa = sum / size;
            cout << "GPA : " << gpa;
        }
        void getYear(int year) {
            int enter = number / 1000000;
            int check = year - enter + 1;
            if (check == 1)
                cout << "Freshmen(1학년)" << endl;
            else if (check == 2)
                cout << "Sophomore(2학년)" << endl;
            else if (check == 3)
                cout << "Junior(3학년)" << endl;
            else if (check == 4)
                cout << "Senior(4학년)" << endl;
            else
                cout << "About to graduate(5학년이상)" << endl;
        }
};


int main() {
	Student Harry("Harry", 2017310973, "CS");
	Harry.print();
	Harry.getYear(2019);
	Harry.addGrade("programming", 'A');
	Harry.addGrade("Basic Circuit", 'B');
	Harry.printGrades();
	cout << "\n\n";

	Student Ron;
	Ron.print();
	cout << "\n";
	Ron.setName("Ron");
	Ron.setID(2014103959);
	Ron.setDpt("EE");
	Ron.print();
	Ron.getYear(2019);
	Ron.addGrade("Computer Architecture", 'B');
	Ron.addGrade("Maching Learning", 'B');
	Ron.addGrade("Computer Vision", 'C');
	Ron.printGrades();
	cout << "\n\n";

	return 0;
}
