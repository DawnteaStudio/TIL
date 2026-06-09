#include <iostream>

using namespace std;

int main(){
    int num = 0;

    while(num != -1){
        cout << "단 수를 입력하세요: ";
        cin >> num;
        if(num < 10 && num > 0){
            for(int i = 1; i <= 9; i++){
                cout<<num<<"*"<<i<<" = " << num * i<<endl;
            }
            cout<<endl;
        }
        else if (num != -1)
            cout << "1부터 9까지의 정수를 입력해주세요." <<endl<<endl;
    }
    cout<<"종료합니다."<<endl;   
}