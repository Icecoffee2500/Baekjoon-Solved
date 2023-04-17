#include <iostream>

using namespace std;

int main()
{
    int ascend, descend, height;
    cin >> ascend >> descend >> height;
    int day = 0;

    if(((height - ascend) % (ascend - descend)) == 0) {
        day = (height - ascend) / (ascend - descend) + 1;
    }
    else {
        day = (height - ascend) / (ascend - descend) + 2;
    }

    cout << day << "\n";
    return 0;
}