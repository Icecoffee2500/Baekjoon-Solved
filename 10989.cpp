#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    int table[10010] = {0,};
    cin >> N;
    int input;

    for (int i = 1; i < N + 1; i++) {
        cin >> input;
        table[input]++;
    }

    for (int i = 1; i < sizeof(table)/sizeof(int); i++) {
        for(int j = 0; j < table[i]; j++) {
            cout << i << "\n";
        }
    }

    return 0;
}