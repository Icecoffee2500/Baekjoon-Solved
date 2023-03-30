#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    while(1) {
        cin >> num1 >> num2;
        if((num1 == 0) && (num2 == 0)) {
            break;
        }
        if(num1 > num2) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    
    return 0;
}