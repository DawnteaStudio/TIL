
#include <iostream>
#include <cmath>
using namespace std;

//int square (int x)
//{
//    return x*x;
//}
//
//int main() {
//    int x;
//    x = 5;
//    cout << square(x) << endl; // square 함수 사용
//
//}

//int get_num();
//int myadd(int x, int y);
//int mysub(int x, int y);
//int mymul(int x, int y);
//float mydiv(int x, int y);
//float addmul(int x, int y, int z);
//float muldiv(int x, int y, int z);
//int addmuladd(int x, int y, int z);
//float subdivsub(int x, int y, int z);
//
//int main() {
//    int x, y, z;
//    x = get_num(); //키보드로부터 값 입력
//    y = get_num();
//    z = get_num();
//
//    cout << "x = " << x << ", y = " << y <<  ", z = " << z << endl;
//    cout << "(x + y) * z = " << addmul(x,y,z) << endl;
//    cout << "(x * y) / z = " << muldiv(x,y,z)<< endl;
//    cout << "(x + y) * (y + z) = " << addmuladd(x,y,z) << endl;
//    cout << "(x - y) / (y - z) = " << subdivsub(x,y,z) << endl;
//
//    return 0;
//}
//
//int get_num() {
//    int num;
//    cout << "Enter a number: ";
//    cin >> num;
//    return num;
//}
//int myadd(int x, int y) {
//    return x+y; }
//int mysub(int x, int y) {
//    return x-y; }
//int mymul(int x, int y) {
//    return x*y; }
//float mydiv(int x, int y) {
//    return float(x)/y; }
//float addmul(int x, int y, int z) {
//    return  mymul(myadd(x,y),z);
//}
//float muldiv(int x, int y, int z) {
//    return  mydiv(mymul(x,y),z);
//}
//int addmuladd(int x, int y, int z) {
//    return mymul(myadd(x,y),myadd(y,z));
//}
//float subdivsub(int x, int y, int z) {
//    return mydiv(mysub(x,y),mysub(y,z));
//}
//int main() {
//    double value;
//    value = 5;
//    cout << sqrt(value)<< endl;
//    cout << exp(value)<< endl;
//    cout << log10(value) << endl; //로그연산(밑:10??)
//    cout << cos(value) << endl;
//
//    return 0;
//}

//void applePrice(int a = 1000) {
//    cout << "Price of an apple is " << a << endl;
//}
//// default augment 중요!
//int main() {
//    applePrice(1500);
//    applePrice(500);
//    applePrice(1000);
//    applePrice();  // default augments
//
//    return 0;
//}

//void print_DOB (int year = 1900,int month = 1,int day = 1){
//
//    cout << "생년월일은 " << year << "년 " << month << "월 " << day << "일입니다."<<endl;
//}
//
//int main() {
//    int x,y,z;
//    print_DOB();
//    cout << "year 입력 : ";
//    cin >> x;
//    cout << "month 입력 : ";
//    cin >> y;
//    cout << "day 입력 : ";
//    cin >> z;
//    print_DOB(x,y,z);
//}

//int main(){
//    double x,y;
//
//    cout << "x = ";
//    cin >> x;
//    cout << "y = ";
//    cin >> y;
//
//    cout << "Rounding up number of " << x << " : " << ceil(x)<<endl;
//    cout << "Rounding down number of " << x << " : " << floor(x)<<endl;
//    cout << "Rounding number of " << x << " : " << round(x)<<endl;
//    cout << "Maximum number between " << x << " and " << y << " : " << max(x,y)<<endl;
//    cout << y << "-th root of " << x << " : " << pow(x,1/y)<<endl;
//    cout << "|" << x << " - " << y << "| = " << fabs(x-y)<<endl;
//
//
//}


void get_data(int& x, int& y){
    cout << "x 입력 : ";
    cin >> x;
    cout << "y 입력 : ";
    cin >> y;
}

void print_call_by_value1 (int x, int y){
    cout << "swap_call_by_value 함수 사용 전" << endl;
    cout << "x = " << x << ", y = " << y << endl;
}
void swap_call_by_value(int x, int y){
    int c = x;
    x = y;
    y = c;
}
void print_call_by_value2 (int x, int y){
    cout << "swap_call_by_value 함수 사용 후" << endl;
    cout << "x = " << x << ", y = " << y<< endl;
}

void print_call_by_reference1 (int& x, int& y){
    cout << "swap_call_by_referece 함수 사용 전" << endl;
    cout << "x = " << x << ", y = " << y << endl;
}
void swap_call_by_reference(int& x, int& y){
    int c = x;
    x = y;
    y = c;
}
void print_call_by_reference2 (int x, int y){
    cout << "swap_call_by_reference 함수 사용 후" << endl;
    cout << "x = " << x << ", y = " << y << endl;
}

int main(){
    int x,y;
    get_data(x,y);
    
    print_call_by_value1(x,y);
    swap_call_by_value (x,y);
    print_call_by_value2(x,y);

    print_call_by_reference1(x,y);
    swap_call_by_reference(x,y);
    print_call_by_reference2(x,y);

    
}

