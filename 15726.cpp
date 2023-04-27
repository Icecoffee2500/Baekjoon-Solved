#include <iostream>

using namespace std;

int main()
{
    double input[3];
    int min_idx = 0;
    double output = 1;
    for(int i = 0; i < 3; i++) {
        cin >> input[i];
    }
    if(input[1] > input[2]) {
        output = input[0] * input[1] / input[2];
    }
    else if(input[1] <= input[2]) {
        output = input[0] * input[2] / input[1];
    }
    cout << (int)output << "\n";

    return 0;
}