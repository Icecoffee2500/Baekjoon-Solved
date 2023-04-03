/** 3중 for문을 쓰는 더러운 문제 #bruteForce **/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    int M;
    int min = 9999999;
    int sum, goal;
    int diff;
    cin >> num >> M;
    int table[num];

    for(int i = 0; i < num; i++) {
        cin >> table[i];
    }
    // sort(table, table + num);
    
    for(int i = 0; i < num-2; i++) {
        for(int j = i + 1; j < num-1; j++) {
            for(int k = j + 1; k < num; k++) {
                sum = table[i] + table[j] + table[k];
                diff = M-sum;
                if((diff >= 0) && (diff < min)) {
                    min = diff;
                    goal = sum;
                }
            }
        }
    }

    cout << goal << "\n";

    return 0;
}