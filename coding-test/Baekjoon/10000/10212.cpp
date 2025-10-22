#include <iostream>
#include <random>
using namespace std;

int main() {
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<int> dist(0, 1); 

    if (dist(gen))
        cout << "Yonsei";
    else
        cout << "Korea";

    return 0;
}
