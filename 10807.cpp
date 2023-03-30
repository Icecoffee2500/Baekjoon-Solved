// <개수세기>
// 입력은 숫자개수, 숫자 배열, 찾고자 하는 숫자
// 출력은 찾고자 하는 숫자의 개수

#include <iostream>

using namespace std;

int main()
{
    // 변수 생성
    int max_num;
    int search_num;
    int output = 0;
    
    // 배열 개수 입력
    cin >> max_num;

    // 배열 생성
    int arr[max_num];
    for(int i = 0; i < max_num; i++)
    {
        cin >> arr[i];
    }

    // 찾고자 하는 숫자 입력
    cin >> search_num;

    // 숫자 찾기
    for(int i = 0; i < max_num; i++)
    {
        if (arr[i] == search_num)
        {
            output++;
        }
    }
    

    // 출력
    cout << output << endl;

    return 0;
}