#include <iostream>

using namespace std;

int main(){
    int input, result = 0;
    cout << "number : ";
    cin >> input;
    if(input >0){
        for(int i = 1; i <= input ; i++){
            if(i % 2 !=0 && i % 3 != 0){
                result += i;
            }
        }
        cout << "sum : " << result << endl;
    }
}   