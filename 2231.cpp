#include <iostream>

using namespace std;

int main()
{
    // 분해합 입력받기
    int input;
    cin >> input;

    int test = 0;
    int copy = 0;

    for(int i = 1; i < input; i++) {
        copy = i;
        test = i;
        while(copy > 0) {
            test += copy % 10;
            copy /= 10;
        }
        if(test == input) {
            cout << i << "\n";
            break;
        }
    }
    
    if(test != input) {
        cout << 0 << "\n";
    }

    return 0;
}