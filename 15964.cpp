// <이상한 기호>
// 입력 : 첫째 줄에 A, B가 주어진다. (1 ≤ A, B ≤ 100,000)
// 출력 : 첫째 줄에 A＠B의 결과를 출력한다.

#include <iostream>

using namespace std;

long long newOP(long long A, long long B);

int main()
{
    // 입력받을 문자열 개수 입력
    long long A, B;
    cin >> A >> B;

    // 문자열 저장 변수
    long long output = newOP(A, B);

    // output 출력
    cout << output << endl;        

    return 0;
}

long long newOP(long long A, long long B)
{
    return (A+B) * (A-B);
}