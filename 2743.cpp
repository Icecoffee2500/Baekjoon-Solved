// <단어 길이 재기>
// 입력은 영어로만 이루어진 단어
// 출력은 단어의 길이

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // 문자열 담을 변수 생성
    string letter;

    // 문자열 입력받기
    cin >> letter;

    // 문자열 길이 출력
    cout << letter.size() << endl;

    return 0;

}