#include <iostream>

using namespace std;

int main()
{
    int table[9][9];
    int max = 0;
    int max_i = 0;
    int max_j = 0;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> table[i][j];
            if(max < table[i][j]) {
                max = table[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    cout << max << "\n";
    cout << max_i + 1 << " " << max_j + 1 << "\n";
    return 0;
}