//
//  main.cpp
//  lab5&6
//
//  Created by 박세원 on 2022/04/08.
//

#include<iostream>
#include<cmath>
#include<iomanip> // setw등 cout 표현을 멋지게
using namespace std;

//int main() {
//    char grade = 'X';
//    int score;
//    cout << "Enter your score: ";
//    cin >> score;
//
//    if (0 <= score && score <= 100) {
//        if (score >= 90)
//            grade = 'A';
//        else{
//            if (score >= 80)
//                grade = 'B';
//            else{
//                if (score >= 70)
//                    grade = 'C';
//                else{
//                    if (score >= 60)
//                        grade = 'D';
//                    else{
//                        grade = 'F';
//                    }
//                }
//            }
//        }
//        cout << "Your grade is " << grade << endl;
//    }
//    else {
//        cout << "The score (" << score << ") is invalid" << endl;
//    }
//
//    return 0;
//}

//int main() {
//    int num = 1;
//    int count = 1;
//    cout.imbue(locale("")); // 세 자리(1,000)마다 쉼표 찍기위함.
//    while (count <= 20) {
//        num = num*2;
//        cout << count << '\t' << setw(10) << num << endl;
//        count++;
//    }
//    return 0;
//}

//int main() {
//    int column = 1, row = 1;
//    while (row <= 10) {
//        while (column <= 10) {
//            int num;
//            if (row == column)
//                num = 1;
//            else
//                num = 0;
//                cout << setw(4) << num;
//                column++;
//        }
//        cout << endl;
//        row++;
//        column = 1;
//    }
//    return 0;
//}


//int main() {
//    int num;
//
//    while (true) {
//        cout << "Enter the number (0, 10]: ";
//        cin >> num;
//        if (0 >= num || num > 10);
//
//        else{
//            break;
//        }
//    }
//    cout << "Success!" << endl;
//    return 0;
//}

//int main() {
//    int num;
//    do {
//        cout << "Enter the number (0, 10]: ";
//        cin >> num;
//    } while (0 >= num || num > 10); //반드시 세미콜론 찍어줌
//    cout << "Success!" << endl;
//    return 0;
//}

//int main() {
//    int n, m;
//    cout << "Enter n for n x m matrix: ";
//    cin >> n;
//    cout << "Enter m for n x m matrix: ";
//    cin >> m;
//    int column = 1, row = 1;
//    while (row <= n) {
//        while (column <= m) {
//            int num = row*column;
//                cout << setw(4) << num;
//                column++;
//        }
//        cout << endl;
//        row++;
//        column = 1;
//    }    return 0;
//}

//int main() {
//    char key;
//    cout << "Enter a key (p or q): ";
//    cin >> key;
//    switch (key) {
//        case 'p':
//        case 'P':
//            cout << "Pause" << endl;
//            break;
//        case 'Q':
//        case 'q':
//            cout << "Quit" << endl;
//            break;
//    default:
//            cout << "Default" << endl;
//            break;
//    }
//    return 0;
//}

//int main(){
//    int num;
//    int count = 1;
//    while(count <= 5){
//        cout << count <<"번째 정수 : ";
//        cin >> num;
//        if((num%2)==0){
//            cout << num << "은(는) 짝수입니다." << endl;
//        }
//        else{
//            cout << num << "은(는) 홀수입니다." << endl;
//        }
//        count++;
//    }
//}

//int main(){
//    int num, result = 0;
//    int count = 1;
//    cout << "(input) " ;
//    cin >> num;
//    while(num >= count){
//        result += count;
//        count++;
//    }
//    cout <<"(output) " << result << endl;
//}

//int main() {
//    int num, result = 0;
//    int count =1;
//    cout << "number : ";
//    cin >> num;
//    while(num >= count){
//        if((count%2)!= 0 && (count%3) != 0){
//            result += count;
//        }
//        else;
//        count++;
//    }
//    cout << "sum : " << result << endl;
//}

//int main(){
//
//    while(true){
//        int num, result = 1, count=1;
//        cout << "단 수를 입력하세요: ";
//        cin >> num;
//
//        if (1 <= num && 9 >= num){
//            while(9 >= count){
//                result = num*count;
//                cout << num << "*" << count << " = " << result << endl;
//                count++;
//            }
//        }
//        else if(num == -1){
//            cout << "종료합니다."<<endl;
//            break;
//        }
//        else if (1 > num || 9 < num){
//            cout << "1부터 9까지의 정수를 입력해주세요." << endl;
//        }
//    }
//}

int gab(int x, int y){
    
    if(y == 0){
        return x;
    }else{
        return gab(y, x%y);
    }
}

int main(){
    int num1, num2;
    cout << "x = ";
    cin >> num1;
    cout << "y = ";
    cin >> num2;
    cout << "gcd(" << num1 << "," << num2 << ") = " << gab(num1,num2) << endl;
   
}
