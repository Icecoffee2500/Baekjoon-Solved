#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int input;
    vector<int> v;
    int sum = 0;

    for(int i = 0; i < 7; i++) {
        cin >> input;
        if(input%2 != 0) {
            v.push_back(input);
            sum += input;
        }
    }
    if(v.empty()) {
        cout << -1 << "\n";
        return 0;
    }
    sort(v.begin(), v.end());
    
    cout << sum << "\n";
    cout << v.front() << "\n";

    return 0;
}