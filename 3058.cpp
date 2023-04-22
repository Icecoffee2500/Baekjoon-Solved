#include <iostream>
#include <utility>

using namespace std;

int main()
{
    int test_case;
    cin >> test_case;
    pair<int, int> table[test_case];

    for(int k = 0; k < test_case; k++) {
        int sum = 0;
        int min = 101;
        for(int i = 0; i < 7; i++) {
            int input;
            cin >> input;
            if(input % 2 == 0) {
                sum += input;
                if(min > input) {
                    min = input;
                }
            }
        }
        table[k] = {sum, min};
    }

    for(int i = 0; i < test_case; i++) {
        cout << table[i].first << " " << table[i].second << "\n";
    }

    return 0;
}