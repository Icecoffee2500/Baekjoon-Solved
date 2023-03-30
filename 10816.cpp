#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int N, M;
    unordered_map<int, int> N_table;
    vector<int> M_table;
    int input;
    int count = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> input;
        if(N_table.count(input)) {
            N_table[input] += 1;
            //cout << "변경된 값은 " << N_table[input] << "입니다.\n";
        }
        else {
            N_table.insert(make_pair(input, 1));
        }
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> input;
        M_table.push_back(N_table[input]);
    }
    for(auto &ele : M_table) {
        cout << ele << " ";
    }
    cout << "\n";
    
    return 0;
}