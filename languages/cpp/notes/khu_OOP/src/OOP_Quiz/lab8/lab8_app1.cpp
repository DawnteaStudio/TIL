#include<iostream>
using namespace std;

void squared(int* x){
    *x *= *x;
    }

int main(){
    int x;
    cout << "input> ";
    cin >>x;
    squared(&x);
    cout << "제곱값> " << x << endl;;
}