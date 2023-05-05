#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int table[num];
    for(int i = 0; i < num; i++) {
        int V, E;
        cin >> V >> E;
        table[i] = E - V + 2;
    }
    for(const auto& ele : table) {
        cout << ele << "\n";
    }
    return 0;
}