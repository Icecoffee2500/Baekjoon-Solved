// <팩토리얼>
// 입력은 N, (0 ≤ N ≤ 12)
// 출력은 N!

#include <iostream>

using namespace std;

int main()
{
    // 변수 생성
    int N;
    int N_fact = 1;
    
    // 입력
    cin >> N;

    // 팩토리얼 구하기
    for (int i = 1; i < N+1; i++)
    {
        N_fact *= i;
    }

    // 출력
    cout << N_fact << endl;

    return 0;
}