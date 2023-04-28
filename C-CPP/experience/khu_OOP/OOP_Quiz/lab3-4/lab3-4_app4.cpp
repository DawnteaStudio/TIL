#include<iostream>

using namespace std;

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
