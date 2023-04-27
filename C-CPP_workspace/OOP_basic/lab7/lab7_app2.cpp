#include <iostream>
#include <string> 

using namespace  std;

int main(){

    string data = "사랑,프로그래밍,의자,사랑의바보,영통역,천년의사랑,냉장고,객체지향";
    string keyword, result = "";
    int searchPoint;
    int startPoint, endPoint;
    cout << "키워드 : ";
    cin >>keyword;
    int count = 0;

    
    while(data.find(keyword) != string::npos){
        searchPoint = data.find(keyword);
        if(data[searchPoint - 1] != ','){
            int cnt = 0;
            while(data[searchPoint-cnt] != ','){
                if(searchPoint == 0){
                    cnt++;
                    break;
                }
                cnt++;
            }
            startPoint = searchPoint - cnt + 1;
            endPoint =  searchPoint + keyword.length();
            result += data.substr(startPoint, endPoint - startPoint) + " ";
            data = data.substr(endPoint);
        }
        else{
            startPoint = searchPoint;
            int cnt = 0;
            while(data[searchPoint + cnt] != ','){
                cnt++;
            }
            endPoint = searchPoint + cnt;
            result += data.substr(startPoint, endPoint - startPoint) + " ";
            data = data.substr(endPoint);
            }
        }
    cout << "검색결과 : " << result << endl;

        
}