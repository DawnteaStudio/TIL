// #include <iostream>
// #include <string> //string객체 사용
// #include <fstream> //ifstream ofstream
// #include <iomanip> // setw
//
// using namespace std;
//
// int main() {
//    string s1 = "mouse";
//    cout << s1 << endl;
//    cout << s1.length() << ", " << s1.size() << endl << endl; //s1의 length, size 출력
//
//    cout << s1.empty() << endl;
//    s1.clear();// s1 = "";
//    cout << s1.empty() << endl;
//
//    s1 = "Good";
//    s1 = s1 + "-bye";
//    // Good-bye (string)
//    // 01234567 (index)
//    cout << s1 << endl;
//    cout << s1[4] << ", " << s1.at(4) << endl; // 두가지 방법으로 index 4 값 출력
//    cout << (s1 == "Good-bye") << endl; // s1과 Good-bye 비교 (bool 값 출력)
//    cout << (s1 == "good-bye") << endl; // s1과 good-bye 비교 (bool 값 출력)
//    cout << (s1 > "z") << endl << endl; // s1이 “z”보다 크거나 같은지 비교 (bool 값 출력)
//
//    cout << s1.substr(5,3) << endl; // s1의 index 5부터 3글자 출력
//    cout << s1.substr(2,2) << endl; // s1의 index 2부터 2글자 출력
//    cout << s1.find("od") << endl; // od 위치 출력
//    cout << s1.find("od", 5) << endl;
//    int od_index = s1.find("od");
//    cout << s1.find("od", od_index + 2);
//    cout << (s1.find("korea") == string::npos) << endl;
//
//    return 0;
//
//}

//#include <iostream>
//#include <string> //string객체 사용
//#include <fstream> //ifstream ofstream
//#include <iomanip> // setw
//
// using namespace std;
//
// int main() {
//    ofstream fout;  // processor->file 저장
//    fout.open("example.txt");        // example.txt 열기
//
//    string s2 = "Objective Oriented Programming";
//    fout << s2 << endl;
//    fout << "Random Variables" << endl;
//    fout << "Linear Algebra" << endl;
//
//    fout.close();        // fout 닫기
//
//    ifstream fin;
//    string s1;
//    fin.open("example.txt");        // example.txt 열기
//    if (!fin) {
//        cout << "Error, no such file exists" << endl;
//        exit(100);
//    }
//
////        while (getline(fin, s1)) { // line by line으로 example.txt에서 읽어와서 출력
////        cout << s1 << endl;
////    }
//
//
////        //한번에 실행되지 않기 때문에 주석처리 해놓음
//        while (1) { // 띄어쓰기 단위로 example.txt에서 읽어와서 출력
//            fin >> s1;
//            if (!fin)
//                break;
//            cout << s1 << endl;
//
//        }
//
//    fin.close();
//
//}

//#include <iostream>
// using namespace std;
//
// int main() {
//    double d1 = 1.23456789;
//
//    cout << d1 << endl;
//
//    cout.width(10);  // 출력값 길이 10로 지정
//    cout.precision(4);  // 주요 자리수 3자리만 출력
//    cout << d1 << endl;
//
//    char ch1;
//    char ch2;
//
//    // ch1, ch2 : enter “ z”. ( space + z )
//    cin >> ch1;
//    cout << "(" << ch1 << ")" << endl;
//
//    cin.ignore(); // enter가 다음 cin으로 들어가지 않도록 해줌
//
//    cin.unsetf(ios::skipws);  // space도 입력으로 생각하게 함
//    cin >> ch2;
//    cout << "(" << ch2 << ")" << endl;
//
//
//    return 0;
//}

//#include <iostream>
//#include <fstream> //ifstream ofstream
//#include <iomanip>
// using namespace std;
//
//
// bool getStu(ifstream& fin, int& id, int& exam1, int& exam2, int& exam3) {
//    fin >> id >> exam1 >> exam2 >> exam3;
//    if (!fin)
//        return false;
//    return true;
//}
//
// void calcAvgGrade(int& exam1, int& exam2, int& exam3, int& avg, char& grade) {
//    avg = (exam1 + exam2 + exam3) / 3;
//    if (avg >= 90)
//        grade = 'A';
//    else if (avg >= 80)
//        grade = 'B';
//    else
//        grade = 'F';
//}
//
// void writeStu(ofstream& fout, int id, int avg, char grade) {
//
//    fout.fill('0');
//    fout << setw(4) << id;
//    fout.fill(' ');
//    fout << setw(4) << avg;
//    fout << setw(4) << grade << endl;
//}
//
//
// int main() {
//    //반복: 모든 학생을 읽고 저장할 때까지
//        //getStu 함수 = ch7STUFL.DAT에서 파일 읽기: id, exam1, exam2, exam3
//        //calcAvgGrade 함수 = 평균,grade 계산: exam1, exam2, exam3 -> avg, grade
//        //writeStu 함수 = grade.txt 저장: id, avg, grade
//
//    ifstream  fin("ch7STUFL.txt"); // 강의 사이트에서 다운로드 가능
//    ofstream  fout("grade.txt");
//    int id, exam1, exam2, exam3, avg;
//    char grade;
//
//    while (getStu(fin, id, exam1, exam2, exam3)) { // getStu함수 사용
//        calcAvgGrade(exam1, exam2, exam3, avg, grade); // calcAvgGrade함수 사용
//        writeStu(fout, id, avg, grade); // writeStu함수 사용
//    }
//
//    fin.close();
//    fout.close();
//
//    cout << "end";
//
//    return 0;
//}

#include <iostream>
#include <string>  //string객체 사용
#include <fstream> //ifstream ofstream

using namespace std;

// int main(){
//     string city, area, street, building,adress;
//     cout << "시 : ";
//     cin >> city;
//     cout << "구 : ";
//     cin >> area;
//     cout << "로 : ";
//     cin >> street;
//     cout << "건물명 : ";
//     cin >> building;
//     cout << endl;
//
//     adress = city+area+street+building;
//     cout << "집 주소 : " << adress << endl;
//
// }

//
int main()
{
    string data = "사랑, 프로그래밍, 의자, 사랑의바보, 영통역, 천년의사랑, 냉장고, 객체지향";
    string keyword;
    string s1;
    cout << "키워드 : 사랑" << endl; // macOS string 에서 한글 자음,모음이 분리되어 keyword 직접 입력했음 시험때는 bootcamp 사용예정
    keyword = "사랑";
    cout << "검색결과 : ";

    int i = 0;
    while (1)
    {
        s1.clear();
        int index = data.find(keyword, i);
        int ref = index;
        if (index == string::npos)
            break;
        if (index == 0)
        {
            while (1)
            {
                if (data.at(ref) == ',')
                {
                    i = ref;
                    break;
                }
                else
                {
                    s1 = s1 + data.at(ref);
                    ref++;
                }
            }
        }
        else
        {
            while (data.at(ref) != ' ')
            {
                ref--;
            }
            while (1)
            {
                ref++;
                if (data.at(ref) == ',')
                {
                    i = ref;
                    break;
                }
                else
                    s1 = s1 + data.at(ref);
            }
        }
        if (data.find(keyword, i) != string::npos)
            cout << s1 << ", ";
        else
            cout << s1;
    }
}

// int main()
//{
//     ofstream ofs;
//     ofs.open("temp.txt");
//     int num;
//     for (int i = 0; i < 100; i++)
//     {
//         num = rand() % 101;
//         ofs << num << " ";
//         if (i % 10 == 9)
//             ofs << endl;
//     }
//     ofs.close();
//     return 0;
// }

// int main()
//{
//     ofstream answer("answer.txt");
//     ifstream file1("4text1.txt");
//     ifstream file2("4text2.txt");
//     string line;
//
//     while (getline(file1, line)) {
//         answer << line << endl;
//     }
//     file1.close();
//
//     answer << endl;
//     while (getline(file2, line)) {
//         answer << line << endl;
//     }
//     file2.close();
//     answer.close();
//
//     return 0;
// }

// int main()
// {
//     char ch;
//     int length;
//     cout << "length = ";
//     cin >> length;
//     ifstream ifs;
//     ofstream ofs;
//     ifs.open("5text.txt");
//     ofs.open("final.txt");
//     int point = 0;
//     while (ifs.get(ch))
//     {
//         if (ch != '\n')
//         {
//             ofs.put(ch);
//             point++;
//             if (point == length)
//             {
//                 ofs.put('\n');
//                 point = 0;
//             }
//         }
//         else{
//             ofs.put(' ');
//             point++;
//             if (point == length)
//             {
//                 ofs.put('\n');
//                 point = 0;
//             }
//         }

//     }
//     ifs.close();
//     ofs.close();
//     return 0;
// }
