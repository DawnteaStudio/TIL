#include <iostream>
#include <string>
using namespace std;

class Account {
	string name, id;
	int balance;
public:
	Account(string _name, string _id, int _balance): 
		name(_name), id(_id), balance(_balance){}
	string getName() const { return name; }
	string getId() const { return id; }
	int getBalance() const { return balance; }

	void operator+(Account& ac) {
		this->balance += ac.balance;
	}
	void operator-(Account& ac) {
		this->balance -= ac.balance;
	}
};
ostream& operator<<(ostream& cout,const Account& ac) {
	cout << "학번: " << ac.getId() << "\t이름 : " << ac.getName() << "\t잔액 : " << ac.getBalance();
	return cout;
}

int main() {
	Account acnt[3] = { 
		Account("장윤호", "2014", 10000), 
		Account("김유민", "2019", 0), 
		Account("박진배", "2013", 5000), 
	};
	
	string input, get;
	while (true) {
		cout << "돈을 보낼 학생의 학번을 입력하세요: ";
		cin >> input;
		if (input == "종료") {
			cout << "종료합니다." << endl;
			for (int k = 0; k < 3; k++) 
				cout << acnt[k] << endl;
			exit(0);
		}

		cout << "돈을 받을 학생의 학번을 입력하세요: ";
		cin >> get;
		if (input == get) continue;

		int stu1 = 1, stu2 = 1;
		int i = 0;
		for (i = 0; i < 3; i++) {
			if (input == acnt[i].getId()) {
				stu1 = 0;
				break;
			}
		}
		if (stu1) {
			cout << "보내는 학생 혹은 받은 학생의 학번이 존재하지 않습니다. 다시 입력해주세요." << endl;
			continue;
		}

		int j = 0;
		for (j = 0; j < 3; j++) {
			if (get == acnt[j].getId()) {
				stu2 = 0;
				break;
			}
		}
		if (stu2) { 
			continue; 
			cout << "보내는 학생 혹은 받은 학생의 학번이 존재하지 않습니다. 다시 입력해주세요." << endl;
		}

		if (acnt[i].getBalance() == 0) { 
			cout << "보내는 학생의 잔액이 부족합니다." << endl;
			continue; 
		}

		acnt[j] + acnt[i];
		acnt[i] - acnt[i];
		cout << "보낸 학생의 잔액 : " << acnt[i] << endl;
		cout << "받은 학생의 잔액 : " << acnt[j] << endl;
	}
	return 0;
}