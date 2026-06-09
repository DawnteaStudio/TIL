#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    srand((unsigned int)time(NULL));
    ofstream ofs;
    ofs.open("temp.txt");
    for(int i = 0;i < 10; i++){
        for(int j = 0; j <10; j++){
            ofs << rand()%101 << " ";
        }
        ofs << '\n';
    }

    ofs.close();
}