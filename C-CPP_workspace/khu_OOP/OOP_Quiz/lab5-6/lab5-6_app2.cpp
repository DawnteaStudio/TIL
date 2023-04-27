#include <iostream>

using namespace std;

int main(){
    int input, result = 0;
    cout << "number : ";
    cin >> input;
    for (int i = 1; i <= input; i++){
        result += i;
    }
    cout << "Sum of 1 to " << input << " = " << result << endl; 
}