#include <iostream>
#include <cmath>
using namespace std;
void applePrice(int a = 1000) {
    cout << "Price of an apple is " << a << endl;
}
// default augment 중요!
int main() {
    applePrice(1500);
    applePrice(500);
    applePrice(1000);
    applePrice();  // default augments

    return 0;
}
