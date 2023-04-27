#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> list{ 10, 20, 30, 40, 50 };
	int num; // 출력할 list의 수
	while (1) {
        cout << "출력 할 숫자의 수 : ";
        cin >> num;
        if(num > 0){
            for(int i = 0; i < num ; i++){
                try{
                    cout<<list.at(i)<<' ';
                }
                catch(exception& e){
                    cout<<endl;
                    cout<<"Index is out of range. Please try again";
                    break;;
                }
            }       
        }
        else{
            cout << "Program exit..." << endl;
            return 0;
        }
        cout<<endl;

    }
	cout << "Program exit..." << endl;
	return 0;
}
