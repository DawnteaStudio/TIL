#include <iostream>
#include <string>
#include <fstream>

using namespace  std;

int main(){
    ifstream txt1, txt2;
    string line;
    txt1.open("text1.txt");
    txt2.open("text2.txt");

    ofstream ofs;

    ofs.open("merge.txt");

    while(getline(txt1,line)){
        ofs << line;
    }

    ofs << '\n' << '\n';

    while(getline(txt2,line)){
        ofs << line;
    }

    ofs.close();
    txt1.close();
    txt2.close();
}