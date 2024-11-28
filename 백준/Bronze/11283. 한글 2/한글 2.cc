#include <iostream>
#include <string>
using namespace std;

int main(){
	string S;
	int N;
	cin>>S;
	N=((S[0]&255)-234)*4096+((S[1]&255)-176)*64+(S[2]&255)-127;
	cout<<N;
}