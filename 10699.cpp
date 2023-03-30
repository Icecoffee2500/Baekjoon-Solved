#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;
using namespace chrono;

int main()
{
    // 현재 시각 가져오기
    const system_clock::time_point Present = system_clock::now();

    // 시각을 "YYYY-MM-DD" 형식으로 변환
    time_t present_time_t = system_clock::to_time_t(Present);
    tm now = *localtime(&present_time_t);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &now);

    // 출력
    cout << buffer << endl;

    return 0;
}