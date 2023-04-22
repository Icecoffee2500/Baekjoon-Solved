#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num, system;
    vector<char> output;

    cin >> num >> system;
    while(num != 0) {
        int output_s = num % system;
        if(output_s > 9) {
            output_s += 55;
        }
        if(output_s <= 9) {
            output_s += 48;
        }
        output.insert(output.begin(), output_s);
        num = num / system;
    }
    for(auto &ele : output) {
        cout << ele;
    }
    cout << "\n";

    return 0;
}