#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int N_fact, K_fact, NK_fact;
    N_fact = 1;
    K_fact = 1;
    NK_fact = 1;
    int binomial;

    if((K < 0) || (K > N)) {
        cout << 0 << "\n";
        return 0;
    }

    for(int i = 1; i <= N; i++) {
        N_fact *= i;
        if(i <= K) {
            K_fact *= i;
        }
        if(i <= N-K) {
            NK_fact *= i;
        }
    }
    binomial = N_fact / (K_fact * NK_fact);
    cout << binomial << "\n";
    return 0;
}