// <검증수>
// 입력 : 첫째 줄에 고유번호의 처음 5자리의 숫자들이 빈칸을 사이에 두고 하나씩 주어진다.
// 출력 : 첫째 줄에 검증수를 출력한다.

#include <iostream>

using namespace std;

int testOP(int arr[5]);

int main()
{
    // 입력받을 문자열 개수 입력
    int num[5];
    for(int i = 0; i < 5; i++)
    {
        cin >> num[i];
    }

    // 문자열 저장 변수
    int output = testOP(num);

    // output 출력
    cout << output << endl;        

    return 0;
}

int testOP(int arr[5])
{
    int output = 0;
    for(int i = 0; i < 5; i++)
    {
        output += arr[i]*arr[i];
    }
    output %= 10;

    return output;
}