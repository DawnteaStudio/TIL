#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


class Avengers {
public:
	Avengers() {
		name = "";
		attack_point = 0;
		defense_point = 0;
		health = 0;
	}
	~Avengers() {}
	// 캐릭터 설정 함수
	virtual void set(string _name, int _attack, int _defense, int _health) {}
	// 공격 함수
	virtual int attack() { return 0; }
	// 방어 함수
	virtual void defense(int _attack_point) { }
	// 캐릭터 정보 출력 함수
	virtual void print_info() { 
        cout << "Name : " << name << "\nAttack_Point : " << attack_point << endl;
		cout << "Defense_Point : " << defense_point << "\nHealth : " << health << endl;
        }
protected:
	string name;		// 캐릭터 이름
	int attack_point;	// 공격력
	int defense_point;	// 방어력
	int health;		// 체력
};

class Character : public Avengers {
public:
	Character() : Avengers() {}
	Character(string _name, int _attack, int _defense, int _health) {
        name = _name, attack_point = _attack, defense_point = _defense, health = _health;
        }
	string get_name() { return name; }
	int get_health() { return health; }

    int attack() override {
		return attack_point;
	}
	void defense (int _attack_point) override {
		health = health - _attack_point + defense_point;
		if (health <= 0) 
			health = 0;
	}


};

int main() {
	Character my_char;
	Character enemy_char;
	
	Character champlist[] = { 
		Character("IronMan", 70, 40, 100),
		Character("CaptainAmerica", 60,50,100),
		Character("Thor", 80, 30, 100)};
	
	string chosenName;
	cout << "Choose your character(IronMan, CaptainAmerica, Thor) : ";
	cin >> chosenName;

	for (int i = 0; i < 3; i++) {
		if (chosenName == champlist[i].get_name()) {
			my_char = champlist[i];
		}
	}

    int enemynumber = 0;
    srand(time(0));
    enemynumber = rand()%3;
    enemy_char = champlist[enemynumber];

    cout << endl << "--My Character--" << endl;
    my_char.print_info();

	cout << endl << "--Enemy Character--" << endl;
    enemy_char.print_info();
    cout << endl;


	cout << endl << "--Battle--" << endl;
	cout << "My Life: " << my_char.get_health() << "\t"
        << "Enemy Life:" << enemy_char.get_health() << endl;
	while (1)  {
		int my_attack = my_char.attack();
		enemy_char.defense(my_attack);

		cout << "My life: " << my_char.get_health() << "\t "
			<< "Enemy Life: " << enemy_char.get_health() << endl;
		if (enemy_char.get_health() == 0) {
			cout << "You Win!" << endl;
			break;
		}
        else if (my_char.get_health() == 0) {
			cout << "You Lose!" << endl;
			break;
		}

		int enemey_attack = enemy_char.attack();
		my_char.defense(enemey_attack);
		
		cout << "My life: " << my_char.get_health() << "\t "
			<< "Enemy Life: " << enemy_char.get_health() << endl;
		if (my_char.get_health() == 0) {
			cout << "You Lose!" << endl;
			break;
		}
        else if (enemy_char.get_health() == 0) {
			cout << "You Win!" << endl;
			break;
		}
	}	

	return 0;
}
