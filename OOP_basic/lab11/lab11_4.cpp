#include <iostream>
#include <string>
using namespace std;

class Account {
	string id, name;
	int balance;

	static int sum;
public:
	Account() : id(""), name(""), balance(0) {}
	void setId(string _id) { id = _id; }
	void setName(string _name) { name = _name; }
	void setBalance(int _balance) { 
		balance = _balance; 
		sum += balance;
	}
	string getId() { return id; }

	static int getSum() { return sum; }
};

int Account::sum = 0;

int main() {

    cout << "총 학생 수 입력: ";
	int num;
	cin >> num;
	Account* acnt = new Account[num];
	for (int i = 1; i < num+1; i++) {
		string id, name;
		int balance;
		cout << i << "번째 학생 계좌 입력 : 학번 : ";
		cin >> id;
		cout <<'\n' << "이름 : ";
		cin >> name;
		cout << '\n' << "잔액 : ";
		cin >> balance;
		cout << "==========================" << endl;

		for (int j = 0; j < i; j++) {
			if (id == acnt[j].getId()) {
				cout << "중복된 학번이 존재합니다." << endl << "프로그램을 종료합니다." << endl;
				exit(0);
			}
		}
        acnt[i].setBalance(balance);
		acnt[i].setName(name);
		acnt[i].setId(id);
	}

	cout << "회수된 금액 : " << Account::getSum() << endl;
	delete[] acnt;
	return 0;
}