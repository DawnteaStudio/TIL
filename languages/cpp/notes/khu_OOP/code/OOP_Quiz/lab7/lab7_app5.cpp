#include <iostream>
#include <string>
#include <fstream>

using namespace  std;

int main(){
    ifstream ifs;
    ofstream ofs;
    string line, result = "";
    int len;
    ifs.open("text3.txt");
    cout << "length = ";
    cin >> len;

    while(getline(ifs, line)){
        result = result + line;
    }

    ofs.open("newtext.txt");
    for(int i = 0; i < result.length(); i++){

        if(result[i] != '\r'){
            ofs << result[i];
        }
        else{
            ofs << ' ';
        }
        if((i+1) % len == 0){
            ofs << '\n';
        }
    }

    ifs.close();
    ofs.close();
}