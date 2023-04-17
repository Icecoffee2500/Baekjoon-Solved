#include <iostream>

using namespace std;

int main()
{
    int input;
    cin >> input;
    for(int i = 0; i < input; i++) {
        for(int j = 0; j < input; j++) {
            if(i <= j) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}