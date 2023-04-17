#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    cin >> num;
    cin.ignore();

    string table[num];
    for(int i = 0; i < num; i++) {
        getline(cin, table[i]);
    }
    for(int i = 0; i < num; i++) {
        cout << i + 1 << ". " << table[i] << "\n";
    }
    return 0;
}