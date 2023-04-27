#include <iostream>
#include <functional>
#include <algorithm> // for_each, copy, transform
#include <vector>
using namespace std;

int main() {
	vector<int> v1 = { 1,2,3,4 };
	for (int& elem : v1) {
		cout << elem << '\t';
	}
	cout << endl;

	// for_each(시작위치(iter), 끝위치(iter), 람다함수)
	for_each(begin(v1),end(v1),[](int x){cout << x << '\t';}); // v1의 시작부터 끝까지 출력, (띄어쓰기는 탭으로)
	cout << endl;

	for_each(begin(v1),end(v1),[](int& elem){elem++;}); // v1의 시작부터 끝까지 모든 elem++
	for_each(begin(v1),end(v1),[](int elem){cout << elem << '\t';}); // v1의 시작부터 끝까지 출력, (띄어쓰기는 탭으로)
	cout << endl;

	int a = 10;
	for_each(begin(v1),end(v1),[&](int& elem){elem += a;}); // v1의 시작부터 끝까지 모든 elem+=a
	for_each(begin(v1),end(v1),[](int x){cout << x << '\t';}); // v1의 시작부터 끝까지 출력, (띄어쓰기는 탭으로)
	cout << endl;

	vector<int> v2(v1.size());
	// copy: container1 (source)의 element를 container 2(destinstion)로 복사 
	// copy(src시작위치, src끝위치, dst시작위치)
	// v1: {1, 2, 3, 4}
	// v2: {0, 0, 2, 3}
	copy(begin(v1)+1,end(v1)-1,begin(v2)+2); // v1의 (시작+1) ~ (끝-1)을 v2의 (시작+2)위치부터 하나씩 복사
	for_each(begin(v2),end(v2),[](int x){cout << x << '\t';}); // v2의 시작부터 끝까지 출력, (띄어쓰기는 탭으로)
	cout << endl; 

	// transform: cont1의 element를 변형한다음(람다함수) cont2에 복사
	// transform(src시작위치, src끝위치, dst시작위치, 람다함수)
	transform(begin(v1),end(v1),begin(v2),[](int x){return x*x;}); // v1의 시작부터 끝까지 제곱해서 v2에 복사
	for_each(begin(v2),end(v2),[](int x){cout << x << '\t';}); // v2의 시작부터 끝까지 출력, (띄어쓰기는 탭으로)
	cout << endl;

	return 0;
}
