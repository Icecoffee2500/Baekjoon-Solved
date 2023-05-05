#include <iostream>
#include <string>

using namespace std;

int main()
{
    int count = 0;
    for(int i = 0; i < 8; i++) {
        string line;
        getline(cin, line);
        if(i % 2 == 0) {
            for(int j = 0; j < 4; j++) {
                if(line.at(2 * j) == 'F') {
                    count++;
                }
            }
        }
        else {
            for(int j = 0; j < 4; j++) {
                if(line.at(2 * j + 1) == 'F') {
                    count++;
                }
            }
        }
    }

    cout << count << "\n";

    return 0;
}