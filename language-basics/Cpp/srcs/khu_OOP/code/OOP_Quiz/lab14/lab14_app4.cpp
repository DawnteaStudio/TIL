#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

class FileNotFoundException : public exception {
	string message;
public:
	FileNotFoundException(string _m) :
		message("File not found: " + _m) {}
	virtual const char* what() const throw() {
		return message.c_str();
	}

};
vector<vector<int>> load_vector(string filename) {
	ifstream fin(filename);

	// 파일이 열리지 않으면(파일이 존재하지x)
	if (!fin) {
		// 예외처리 (throw)
		throw FileNotFoundException(filename);
	}

	vector<vector<int>>result(10, vector<int>(10) );
        int num;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                fin >> num;
                result[i][j] = num;
            }
        }
    
	return result;
}
int main()
{
    srand((int)time(NULL));
	ofstream ofs;
	ofs.open("temp.txt");
	// 임의의 10x10 행렬 저장 구현
    
    for (int i = 0; i < 100; i++){
        int num = rand()%100;
		ofs << num << " ";
		if (i % 10 == 9)
			ofs << endl;
        }
    
	ofs.close();

	// 파일이름 입력
    string name;
    int row, col;
    vector<vector<int>> v(10, vector<int>(10));
    cout << "파일 이름 : ";
    cin >> name;
	try {
        v = load_vector(name);
        cout << "출력할 행 크기 :";
        cin >> row;
        cout << "출력할 열 크기 :";
        cin >> col;
        try{
            for(int i = 0; i < row; i++){
                for(int j =0; j<col; j++){
                    cout<< v.at(i).at(j)<<" ";
                }
                cout<<endl;
            }
        }
        catch (exception& e){
            cout << "invalid "<< e.what()<<"<T> subscript" << endl;
        }

	}
    catch (exception& e) {
        cout << endl;
		cout << e.what() << endl;
	}
	return 0;
}
