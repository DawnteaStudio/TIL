#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int* makearr(int n){
    int* arr = new int[n/2];
    return arr;
}

void setarr(int* arr, int n){
    for(int i = 0; i < n/2; i++){
        *arr = rand()%n + 1;
        arr++;
    }
}

void printarr(int* arr, int n){
    cout << "[ Array ]" << endl;
    for(int i = 0; i < n/2; i++){
        cout << *arr << " ";
        arr++;
    }
    cout << endl;
}

int checkarr(int* arr, int n){
    for(int i = 0; i <n/2; i++){
        for(int j = i+1; j<n/2; j++){
            if(*(arr+i) == *(arr+j)){
                cout << "Duplicates found." << endl;
                return 0;
            }
        }
    }
    cout << "Duplicates not found." << endl;
    return 0;
}

int main(){
    int num;
    srand((unsigned int)time(NULL));
    while(true){
        cout << "Please enter a number : ";
        cin >> num;
        if(num > 1){
            cout << "Size of random array : " << num/2 << endl;
            int* arr = makearr(num);
            setarr(arr, num);
            printarr(arr, num);
            checkarr(arr, num);
            delete[] arr;
        }
        else{
            cout << "Wrong number!!!" <<endl;
            break;
        }
    }
    
}

