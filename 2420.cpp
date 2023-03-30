#include <iostream>

using namespace std;

int main()
{
    // 변수 생성
    long long N, M;
    long long difference;
    
    // 입력
    cin >> N >> M;

    // 차이 구하기
    difference = N - M;
    if(difference < 0) {
        difference *= -1;
    }

    // 출력
    cout << difference << endl;

    return 0;
}