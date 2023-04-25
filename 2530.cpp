#include <iostream>

using namespace std;

int main()
{
    int hour, min, sec, time;
    cin >> hour >> min >> sec;
    cin >> time;

    hour += time / 3600;
    time -= (time / 3600) * 3600;
    min += time / 60;
    time -= (time / 60) * 60;
    sec += time;

    if(sec >= 60) {
        min += sec / 60;
        sec = sec % 60;
    }
    if(min >= 60) {
        hour += min / 60;
        min = min % 60;
    }
    if(hour >= 24) {
        hour %= 24;
    }

    cout << hour << " " << min << " " << sec << "\n";

    return 0;
}