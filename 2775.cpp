#include <iostream>

using namespace std;

int howMany(int floor, int number);

int main()
{
    int count, floor, number;
    cin >> count;
    for(int i = 0; i < count; i++) {
        cin >> floor >> number;
        cout << howMany(floor, number) << "\n";
    }
    return 0;
}
int howMany(int floor, int number)
{
    if(floor < 1) return -1;
    int how_many_people = 0;
    int table[floor][number];
    for(auto &row : table) {
        for(auto &col : row) {
            col = 0;
        }
    }
    for(int i = 0; i < number; i++) {
        table[0][i] = i + 1;
    }
    for(int i = 0; i < floor; i++) {
        table[i][0] = 1;
    }
    /* for(auto &row : table) {
        for(auto &col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl; */
    for(int i = 1; i < floor; i ++) {
        for(int j = 1; j < number; j++) {
            table[i][j] = table[i-1][j] + table[i][j-1];
        }
    }
    /* for(auto &row : table) {
        for(auto &col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl; */

    for(int i = 0; i < number; i++) {
        how_many_people += table[floor-1][i];
    }
    return how_many_people;
}