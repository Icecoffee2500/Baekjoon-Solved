#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int sum = 0;
    int A, B;
    for(int i = 1; i <= 45; i++) {
        for(int j = 0; j < i; j++) {
            v.push_back(i);
        }
    }
    cin >> A >> B;
    for(int i = A-1; i < B; i++) {
        sum += v.at(i);
    }
    cout << sum << endl;
    return 0;
}