#include <iostream>

using namespace std;

int main()
{
    int stu[5];
    int sum = 0;
    for(auto &ele : stu) {
        cin >> ele;
        if(ele < 40) {
            ele = 40;
        }
        sum += ele;
    }

    cout << sum / 5 << "\n";
    return 0;
}