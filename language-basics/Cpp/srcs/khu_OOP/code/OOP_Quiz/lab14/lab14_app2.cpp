#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


int main() {
	vector<int> list;
	// vector를 1~100 사이의 random한 크기로 만들고 채우는 코드 구현
    srand((int)time(NULL));
    int num = rand()%100+1;
    list.resize(num);
	int cnt = -1;
	while (1) {
		cnt++;
		try {         
            list.at(cnt);            
            }
		catch (exception& e) {
            cout<<"현재 list는" << cnt<<"의 크기를 가지고 있다."<<endl;
            break;
            }
	}
	return 0;
}
