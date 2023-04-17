#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int test(int &duration, int &height, int &inven, vector<int> &table);

int main()
{
    int row, col, inven, input;
    float sum = 0;
    cin >> row >> col >> inven;
    vector<int> table;
    int duration = 0;

    for(int i = 0; i < row * col; i++) {
        cin >> input;
        table.push_back(input);
        sum += input;
    }
    cout << endl;

    sort(table.begin(), table.end(), compare);

    int avg = round(sum / (row * col));
    int target_height = avg;
    int target_height_copy = target_height;

    while(test(duration, target_height_copy, inven, table) == -1) {
        target_height--;
        target_height_copy = target_height;
        duration = 0;
    }
    cout << duration << " " << target_height << "\n";
    return 0;
}

int test(int &duration, int &height, int &inven, vector<int> &table)
{
    for(auto &ele : table) {
        if(height > ele) {
            inven += (ele - height);
            duration += 1;
        }
        else if(height < ele) {
            inven += (ele - height);
            duration += 2;
        }
        //cout << "inven is " << inven << "\n";
        if(inven < 0) {
            return -1;
        }
    }
    return 0;
}