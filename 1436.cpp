#include <iostream>
#include <string>

using namespace std;

void findFinal(int num);

int main()
{
    int N;
    cin >> N;

    findFinal(N);
    
    return 0;
}

// num번째 종말의 수를 찾아주는 함수
void findFinal(int num)
{
    int F_num = 665;
    int count = 0;
    string S_num;

    while(count < num)
    {
        S_num = to_string(F_num); // 숫자를 1증가할 때마다 666과의 검사를 위해 문자열로 바꿔준다.
        if(S_num.find("666") != string::npos) // 바꿔준 문자에 666이라는 문자가 있는지 검사해서 있으면 count에 1증가
        {
            count++;
        }
        F_num++;
    }

    cout << --F_num << endl;

    return;
}