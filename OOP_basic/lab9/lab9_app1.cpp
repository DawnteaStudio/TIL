#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main(){
    int lowA, lowB, colA, colB;
    srand((unsigned int)time(NULL));
    int random = (rand()%9)-9;
    cout << "A의 행, 열의 크기를 입력해주세요 : ";
    cin >> lowA >> colA;
    cout << "B의 행, 열의 크기를 입력해주세요 : ";
    cin >> lowB >> colB;

    vector<vector<int>> matA{lowA,vector<int>{colA}};
    vector<vector<int>> matB{lowB,vector<int>{colB}};
    vector<vector<int>> matC{lowA,vector<int>{colB}};


    if(lowA > 0 && lowB > 0 && colA > 0 && colB >0){
        cout << "A행렬 : " << endl;
        for(int i = 0; i < lowA ; i++){
            for(int j = 0; j < colA; j++){
                matA[i].push_back(random);
                cout << setw(4) << matA[i][j];
            }
            cout << endl;
        }

        cout << "B행렬 : " << endl;
        for(int i = 0; i < lowB ; i++){
            for(int j = 0; j < colA; j++){
                matB[i].push_back(random);
                cout << setw(4) << matB[i][j];
            }
            cout << endl;
        }
        if(colA == lowB){
            cout << "AB 곱행렬 : " << endl;
            for(int i = 0; i < lowA ; i++){
                for(int j = 0; j < colB; j++){
                    matA[i][j] * matB[j][i];
                }
                cout << endl;
            }
        }
    }
    else{
        cout << "행렬을 생성할 수 없습니다." << endl;
    }
}