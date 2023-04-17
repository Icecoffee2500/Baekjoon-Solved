#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int BoxA = 3;
    int BoxB = 5;
    int N;
    cin >> N;
    
    int min = 5001;

    for(int i = 0; i <= N/BoxA; i++) {
        for (int j = 0; j <= N/BoxB; j++) {
            int sum = i * BoxA + j * BoxB;
            // cout << "sum : " << sum << "\n";
            if((sum == N) && (i+j < min)) {
                // cout << "i : " << i << ", j : " << j << "\n";
                min = i+j;
            }
        }
    }
    if(min == 5001) {
        min = -1;
    }
    // pq.push()
    

    cout << min << "\n";
    return 0;
}