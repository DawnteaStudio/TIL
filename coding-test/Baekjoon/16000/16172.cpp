#include <iostream>
#include <string>
using namespace std;

string S,K,tmp;

int main(){
    cin>>S>>K;

    for(int i=0; i<S.length(); i++) if(isalpha(S[i])) tmp.push_back(S[i]);

    if(tmp.find(K)==string::npos) cout<<"0";
    else cout<<"1";

}