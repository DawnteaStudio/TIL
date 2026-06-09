#include <iostream>
#include <string>
#include <vector>
using namespace std;

void reverse(vector<int>& vec){
    for (int i=0; i < vec.size()/2; i++) {
		int tmp =vec[i];
		vec[i] = vec[9 - i];
		vec[9 - i] = tmp;
	}
}

int main(){
    int i = 1;
    vector<int> vec(10);
    for(int& elem : vec){
        elem = i;
        i++;
    }
    cout << "기본 Vector 값:" << endl;
    for(int elem: vec){
        cout <<" "<< elem; 
    }
    reverse(vec);
    cout << endl;
    cout << "함수 실행 후 Vector 값:" << endl;
    for(int elem: vec){
        cout <<" "<< elem; 
    }
    cout << endl;
}