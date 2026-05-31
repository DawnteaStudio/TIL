#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

int randnum(){
    int ran = (rand()%19)-9;
    return ran;    
}

int main(){
    int lowA, lowB, colA, colB;
    srand((unsigned int)time(NULL));
    cout << "A의 행, 열의 크기를 입력해주세요 : ";
    cin >> lowA >> colA;
    cout << "B의 행, 열의 크기를 입력해주세요 : ";
    cin >> lowB >> colB;
    vector<vector<int>> matA(lowA,vector<int>(colA));
    vector<vector<int>> matB(lowB,vector<int>(colB));
    vector<vector<int>> matC(lowA,vector<int>(colB));


    if(lowA > 0 && lowB > 0 && colA > 0 && colB >0){
        cout << "A행렬 : " << endl;
        for(int i = 0; i < lowA ; i++){
            for(int j = 0; j < colA; j++){
                matA[i][j] = randnum();
                cout << setw(4) << matA[i][j];
            }
            cout << endl;
        }

        cout << "B행렬 : " << endl;
        for(int i = 0; i < lowB ; i++){
            for(int j = 0; j < colB; j++){
                matB[i][j] = randnum();
                cout << setw(4) << matB[i][j];
            }
            cout << endl;
        }
        if(colA == lowB){
            int x = 0, y = 0;
            cout << "AB 곱행렬 : " << endl;
            for(int i = 0; i < lowA ; i++){
                for(int j = 0; j < colB; j++){
                    int n = 0;
                    for(int m = 0; m < colA ; m++){
                        matC[x][y] += matA[i][m] * matB[n][j];
                        n++;
                    }
                    cout << setw(4) << matC[x][y];
                    y++;
                }
                x++;
                cout << endl;
            }
        }
        else{
            cout << "두 행렬을 곱할 수 없습니다." << endl;
        }
    }
    else{
        cout << "행렬을 생성할 수 없습니다." << endl;
    }
}