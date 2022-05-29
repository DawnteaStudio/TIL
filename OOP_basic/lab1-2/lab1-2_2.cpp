//
//  main.cpp
//  lab01&02
//
//  Created by 박세원 on 2022/03/18.
//

#include <iostream>
using namespace std;
//
//int main() {
//    int x, y;
//    x = 10;
//    y = 20;
//    cout << x << endl;
//    cout << y << endl;
//}

//sizeof 함수는 괄호안 변수의 byte단위 크기를 알려주는 함수이다.
//int main() {
//    unsigned short siX; // (int) 생략 가능
//    unsigned iX;
//    long liX;
//    long long lliX;
//    cout << "sizeof(siX):" << sizeof(siX) << endl;
//    cout << "sizeof(iX):" << sizeof(iX) << endl;
//    cout << "sizeof(liX):" << sizeof(liX) << endl;
//    cout << "sizeof(lliX):" << sizeof(lliX) << endl;
//}

//int main() {
//    cout << "(7 == 5):" << (7 == 5) << endl;
//    cout << "(7 >= 5):" << (7 >= 5) << endl;
//    cout << "(7 != 5):" << (7 != 5) << endl;
//    cout << "(7 <= 5):" << (7 <= 5) << endl;
//    cout << "(7 >= 5 ? 100 : -100): " << (7 >= 5 ? 100 : -100) << endl;
//}

//int main() {
//    const float PI = 3.14;
//    char ch1 = 65;
//    char ch2 = ch1 + 32;
//    cout << PI << endl;
//    cout << ch1 << endl;
//    cout << ch2 << endl;
//}

//int main() {
//    int x, y, sum, mult;
//    float div;
//    cin >> x >> y;
//    sum = x+y;
//    mult = x*y;
//    div = float(x)/y;
//    cout << x << '\t' << y << endl;
//    cout << "x + y = " << sum << endl;
//    cout << "x * y = " << mult << endl;
//    cout << "x / y = " << div << endl;
//}

//int main() {
//    cout << "My name is 박세원"<<endl;
//}

//int main() {
//    int A, B, sum,sub, mult, mod;
//    float div;
//    cin >> A >> B;
//    sum = A+B;
//    sub = A-B;
//    mult = A*B;
//    mod = A%B;
//    div = float(A)/B;
//    cout << A << '\t' << B << endl;
//    cout << "A + B = " << sum << endl;
//    cout << "A - B = " << sub << endl;
//    cout << "A * B = " << mult << endl;
//    cout << "A / B = " << div << endl;
//    cout << "A & B = " << mod << endl;
//}

//int main(){
//    int i1 = 2, i2 = 5, i3 = -3;
//    double d1 = 2.0, d2 = 5.0, d3 = -0.5;
//
//    cout << i1 + (i2 * i3)<< endl;
//    cout << i1 * (i2 + i3)<< endl;
//    cout << i1 / (i2 + i3)<< endl;
//    cout << i1 / i2 + i3<< endl;
//    cout << 3 + 4 + 5 / 3<< endl;
//    cout << (3 + 4 + 5) / 3<< endl;
//    cout << d1 + (d2 * d3)<< endl;
//    cout << d1 + d2 * d3<< endl;
//    cout << d1 / d2 - d3 << endl;
//    cout << d1 / (d2 - d3) << endl;
//    cout << d1 + d2 + d3 / 3<< endl;
//    cout << (d1 + d2 + d3) / 3<< endl;
//}

//int main(){
//    int A,B,C;
//    cin >> A >> B;
//    cout << "A : " << A << endl;
//    cout << "B : " << B << endl;
//    C = A;
//    A = B;
//    B = C;
//    cout << "value of A is : " << A << endl;
//    cout << "value of B is : " << B << endl;
//}

int main(){
    double Fa,Cel;
    cin >> Fa;
    Cel = 5./9 * ( Fa - 32 );
    cout << "Please enter Fahrenheit value : " << Fa << endl;
    cout << "Celsius value is " << Cel << endl;
}
