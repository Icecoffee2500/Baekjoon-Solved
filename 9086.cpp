// <문자열>
// 문자열을 입력으로 주면 문자열의 첫 글자와 마지막 글자를 출력하는 프로그램

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    // 입력받을 문자열 개수 입력
    int num;
    cin >> num;
    cin.ignore();

    // 문자열 저장 변수
    string sentence[num];
    string output[num];

    for(int i = 0; i < num; i++)
    {
        output[i] = "";
    }

    // output에 문자열의 첫글자와 끝글자 저장
    for(int i = 0; i < num; i++)
    {
        getline(cin, sentence[i]);
        //cout << sentence[i] << endl;
        output[i] = output[i] + sentence[i].front() + sentence[i].back();        
    }
    
    // output 출력
    for(int i = 0; i < num; i++)
    {
        cout << output[i] << endl;        
    }

    return 0;
}