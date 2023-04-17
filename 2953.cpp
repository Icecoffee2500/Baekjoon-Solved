#include <iostream>

using namespace std;

int main()
{
    int table[5] = {0, };
    int input;
    int max = 0;
    int max_idx;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> input;
            table[i] += input;
        }
    }
    for(int i = 0; i < 5; i++) {
        if(table[i] > max) {
            max = table[i];
            max_idx = i;
        }
    }
    cout << max_idx + 1 << " " << max << "\n";

    return 0;
}