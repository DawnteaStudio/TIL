#include<iostream>
using namespace std;

int sum(int x, int y) {
    return x + y; 
    }
int mult(int x, int y) {
    return x * y; 
    }
// 함수 func의 포인터와 파라미터 x, y를 받아와서 함수 func의 실행값을 리턴해주는 함수
int evaluate(int (*func)(int, int), int x, int y){
	return func(x, y);
    }

int main() {
	int(*func)(int, int);
    func = &sum;
	cout << func(10, 20) << endl;
    func = &mult;
	cout << func(10, 20) << endl;
	cout << evaluate(&sum, 100, 200) << endl;
	cout << evaluate(&mult, 100, 200) << endl;
	return 0;
}
