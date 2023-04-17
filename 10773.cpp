#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int K;
    cin >> K;
    int input;
    int sum = 0;
    vector<int> v;

    for(int i = 0; i < K; i++) {
        cin >> input;
        if(input != 0) {
            v.push_back(input);
        }
        else {
            v.pop_back();
        }
    }

    for(const auto &ele : v) {
        sum += ele;
    }
    cout << sum << "\n";

    return 0;
}