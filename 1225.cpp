#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long sum = 0;

    string A, B;
    cin >> A >> B;

    for(int i = 0; i < A.length(); i++) {
        for(int j = 0; j < B.length(); j++) {
            sum += int(A[i] - '0') * int(B[j] - '0');
        }
    }

    cout << sum << "\n";
    
    return 0;
}