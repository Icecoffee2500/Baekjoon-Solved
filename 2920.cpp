// <음계>
// 입력 : 첫째 줄에 8개 숫자가 주어진다. 이 숫자는 문제 설명에서 설명한 음이며, 1부터 8까지 숫자가 한 번씩 등장한다.
// 출력 : 첫째 줄에 ascending, descending, mixed 중 하나를 출력한다.

#include <iostream>

using namespace std;

void decisionScale(int arr[]);

int main()
{
    // 입력받을 음계 배열 선언 및 입력 받기
    int scale[8];
    for(int i = 0; i < 8; i++)
    {
        cin >> scale[i];
    }

    // 음계 출력
    decisionScale(scale);      

    return 0;
}

void decisionScale(int arr[])
{
    int count = 0;

    for(int i = 0; i < 8; i++)
    {
        if(arr[i] == (i + 1))
        {
            count++;
        }
        else if(arr[i] == (8 - i))
        {
            count--;
        }
    }
    if(count == 8)
    {
        cout << "ascending" << endl;
    }
    else if(count == -8)
    {
        cout << "descending" << endl;
    }
    else
    {
        cout << "mixed" << endl;
    }
    
    return;
}