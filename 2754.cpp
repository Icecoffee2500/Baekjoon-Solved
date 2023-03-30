// <학점계산>
// 입력은 영어로 된 성적
// 출력은 평점

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int main()
{
    // 변수 생성
    string grade;
    double grade_num;

    // 성적 입력받기
    cin >> grade;

    // 성적 -> 평점
    map<string, string> m = {
	{"A+", "4.3"}, {"A0", "4.0"}, {"A-", "3.7"}
	,{"B+", "3.3"},{"B0", "3.0"},{"B-", "2.7"}
	,{"C+", "2.3"},{"C0", "2.0"},{"C-", "1.7"}
	,{"D+", "1.3"},{"D0", "1.0"},{"D-", "0.7"}
	,{"F", "0.0"}
    };
    
    // 평점 출력
    cout << m.find(grade)->second << endl;

    return 0;

}