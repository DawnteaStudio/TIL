#include <iostream>
#include <string>
#include "text.h"
#include "fixedtext.h"
#include "fancytext.h"
using namespace std;



// 함수 오버로딩: int    sum(int x, int y), 
//                double sum(double x, double y)
//                float  sum(float x, float y, float z)
// 함수 오버라이딩 (상속의 특수한 경우 사용)
//void Text::append(string _extra)
//void Fancy::append(string _extra)



int main() {
	Text t1("Plain");
	t1.append("A");
	cout << t1.get() << endl;

	FancyText t2("Fancy", "<<", ">>", "***");
	t2.append("A");
	cout << t2.get() << endl;

	FixedText t3;
	t3.append("A");
	cout << t3.get() << endl;
	t1 = t2; // Base <- Derived 가능
	//t2 = t1; // Derived <- Base 불가능

	return 0;
}
