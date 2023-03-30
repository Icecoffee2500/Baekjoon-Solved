#include <iostream>
#include <string>

using namespace std;

int main()
{
    int H, W, T, N;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> H >> W >> N;
        int first, second;
        string number;
        
        if(N % H == 0) {
            first = H;
            second = N / H;
        }
        else {
            first = N % H;
            second = N / H + 1;
        }

        if(second < 10) {
            number = to_string(first) + "0" + to_string(second);
        }
        if(second >= 10) {
            number = to_string(first) + to_string(second);
        }
        cout << number << "\n";
    }
    return 0;
}