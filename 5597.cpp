// <과제 안 내신 분...?>
// 입력은 28개의 숫자
// 출력은 안 부른 2개의 숫자

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    // 배열 및 변수 생성
    int arr[30] = {0, };
    int input;
    
    // 입력받는 숫자 1로 바꾸기
    for(int i = 0; i < 28; i++)
    {
        cin >> input;
        if (input > 30)
        {
            cout << "Error : Too High!" << endl;
            return 0;
        }
        arr[input - 1] = 1;
    }

    // 출력
    for(int i = 0; i < 30; i++)
    {
        if(arr[i] == 0)
        {
            cout << i + 1 << endl;
        }
    }
    return 0;
}