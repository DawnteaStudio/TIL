#include <string>
#include <iostream>
using namespace std;

string reverse(string line) {
    string result = "";
    int len = line.length();
    for (int i = 0; i < len; i++) {
        result += line[line.length() - 1];
        line = line.substr(0,line.length()-1);
    }
    return result;
}

int main() {
    while (true) {
        string input;
        cout << "문자열 하나를 입력해주세요 : ";
        cin >> input;
        if(input == "q" || input == "Q"){
            cout<<"반복을 종료합니다."<<endl;
            exit(0);
        }
        string line = reverse(input);
        cout << "입력하신 문자열의 역순 : " << line << endl;
        
        [](string input, string rev) {
            if (input == rev)
                cout << "이 문자는 회문입니다.\n";
            else cout << "이 문자는 회문이 아닙니다.\n"; 
            }
            (input, line);
        cout << endl;
    }
}
