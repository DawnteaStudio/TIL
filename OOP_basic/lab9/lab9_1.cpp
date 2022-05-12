#include <vector>
#include <random>
#include <iomanip>
using namespace std;

vector<vector<int> > input(int row, int col) {
	vector<vector<int> > matrix(row, vector<int>(col));
	for (vector<int>& v : matrix) {
		for (int& elem : v)
			elem = rand() % 19 - 9;
	}
	return matrix;
}

void print_vec(vector<vector<int> > v) {
	for (vector<int>& v1 : v) {
		for (int& elem : v1)
			cout << setw(6) << elem;
		cout << endl;
	}
	cout << endl;
}

vector<vector<int> > multiply(vector<vector<int> >A, vector<vector<int> >B) {
	int row1 = A.size(), col1 = A[0].size();
	int row2 = B.size(), col2 = B[0].size();
	vector<vector<int> > matrix(row1,vector<int>(col2));

	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++){
			matrix[i][j] = 0;
			for (int k = 0; k < col1; k++) 
				matrix[i][j] += A[i][k] * B[k][j];
		}
	}
	return matrix;
}

int main() {
	cout << "A의 행, 열의 크기를 입력해주세요 : ";
	int row1, row2, col1, col2;
	cin >> row1 >> col1;
	cout << "B의 행, 열의 크기를 입력해주세요 : ";
	cin >> row2 >> col2;

	vector<vector<int> > A = input(row1, col1);

	vector<vector<int> > B = input(row2, col2);

	cout << "A 행렬 :\n";
	print_vec(A);
	cout << "B 행렬 :\n";
	print_vec(B);

	if (col1 != row2) {
		cout << "두 행렬을 곱할 수 없습니다.";
		return 0;
	}

	vector<vector<int> > AB = multiply(A, B);
	cout << "AB 곱행렬 :\n";
	print_vec(AB);
    cout << endl;
	return 0;
}