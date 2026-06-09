#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Train {
public:
	Train() {}
	Train(int people) { mPeople = people;}
	~Train() {}
	virtual int station(int takeOff, int takeOn) {mPeople = mPeople - takeOff + takeOn; }
protected:
	int mPeople; // 사람 수
};
class Ktx : public Train {
public:
	Ktx() : Train(0) {}
	Ktx(int people) : Train(people) {}
	~Ktx() {}
	// 기차에 사람이 타고 내리는 함수
	int station(int takeOff, int takeOn) { return Train::station(takeOff, takeOn);}
	int getPeople() { return mPeople; }
};

int main()
{
    int maxPeople = 0;
    int outcode = 0;
	Ktx k;
	int count = 0;
	while (count < 5 && outcode == 0) {
		while (true) {
			int out, in;
			cout << count + 1 << "번역 : ";
			cin >> out >> in;	
			if (k.getPeople() - out < 0) {
				cout << "정원미달입니다" << endl;
                outcode = 1;
				break;
			}
			else if (k.getPeople() - out + in > 300) {
				cout << "정원초과입니다" << endl;
                outcode = 2;
				break;
			}
			else {
				k.station(out, in);
				if (k.getPeople() > maxPeople) 
                    maxPeople = k.getPeople();
				break;
			}
		}
		count++;
	}
    if(outcode == 0)
        cout << "가장 많은 사람이 탑승 했을 때의 사람 수 = " << maxPeople << endl;
	return 0;
}
