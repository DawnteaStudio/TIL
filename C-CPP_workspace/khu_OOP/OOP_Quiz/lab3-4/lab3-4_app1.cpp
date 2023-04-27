#include <iostream>

using namespace std;

int myadd(int x, int y);
int mysub(int x, int y);
int mymul(int x, int y);
float mydiv(int x, int y);

int addmul(int x, int y, int z); // return value: (x + y) * z
double muldiv(int x, int y, int z); // return value: (x * y) / z
int addmuladd(int x, int y, int z); // return value: (x + y) * (y + z)
double subdivsub(int x, int y, int z); // return value: (x - y) / (y - z)



int main() {
    int x,y,z;

    cout << "Enter a number : ";
    cin >> x;
    cout << "Enter a number : ";
    cin >> y;
    cout << "Enter a number : ";
    cin >> z;
    cout << "x = " << x <<", y = " << y << ", z = " << z <<endl;
    cout << addmul(x,y,z) << endl;
    cout << muldiv(x,y,z) << endl;
    cout << addmuladd(x,y,z) << endl;
    cout << subdivsub(x,y,z) << endl;
}

int myadd(int x, int y) {
    return x+y; }
int mysub(int x, int y) {
    return x-y; }
int mymul(int x, int y) {
    return x*y; }
float mydiv(int x, int y) {
    return float(x)/y; }

int addmul(int x, int y, int z){
    cout << "(x + y) * z = ";
    return mymul(myadd(x,y),z);
}
double muldiv(int x, int y, int z){
    cout << "(x * y) / z  = ";
    return mydiv(mymul(x,y), double(z));
    }
int addmuladd(int x, int y, int z){
    cout << "(x + y) * (y + z) = ";
    return mymul(myadd(x,y), myadd(y,z));
    }
double subdivsub(int x, int y, int z){
    cout << "(x - y) / (y - z) = ";
    return mydiv(mysub(x,y), double(mysub(y,z)));
    }