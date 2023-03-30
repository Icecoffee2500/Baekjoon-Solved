// <학점계산>
// 입력은 알파벳 소문자, 대문자, 공백, 숫자로만 이루어져 있다.
// 출력은 입력받은 그대로 출력

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    // 변수 생성
    string sentence;
    string output;

    // 성적 입력받기
    while(1)
    {
        getline(cin, sentence);
        output = output + sentence + "\n";
        if(sentence == "") {
            break;
        }
    }
    
    // 평점 출력
    cout << output << endl;

    return 0;

}