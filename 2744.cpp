// <대소문자 바꾸기>
// 입력은 영어 대소문자로만 이루어진 단어
// 출력은 대소문자를 바꾼 영어단어

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    // 문자열 담을 변수 생성
    char letter[101] = { };

    // 문자열 입력받기
    cin >> letter;

    // 문자열 대소문자 바꾸기
    for(int i = 0; i < strlen(letter); i++)
    {
        if((letter[i] > 64) && (letter[i] < 91))
        {
            letter[i] += 32;
        }
        else if((letter[i] > 96) && (letter[i] < 123))
        {
            letter[i] -= 32;
        }
    }

    // 문자열 출력
    cout << letter << endl;

    return 0;

}