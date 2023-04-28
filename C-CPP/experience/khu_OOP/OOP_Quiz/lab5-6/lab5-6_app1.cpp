#include <iostream>
using namespace std;

int main(){
    int input;
    for(int num =1 ; num <= 5; num++){
        cout << num <<"번째 정수 : ";
        cin >> input;
        if(input % 2 == 0){
            cout << input << "은(는) 짝수입니다."<<endl;
        }
        else
            cout << input << "은(는) 홀수입니다."<<endl;
    }
}