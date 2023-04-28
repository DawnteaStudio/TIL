#include <iostream>

using namespace std;

int gab(int x, int y){
    
    if(y == 0){
            return x;
    }

    else if( y > x){
        return gab(y, x);
    }

    
    else{
        return gab(y, x%y);
    }
}

int main(){
    int num1, num2;
    cout << "x = ";
    cin >> num1;
    cout << "y = ";
    cin >> num2;
    cout << "gcd(" << num1 << "," << num2 << ") = " << gab(num1,num2) << endl;

}