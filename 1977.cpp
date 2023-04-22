#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int M, N;
    int sum = 0;
    int min = 10001;

    cin >> M >> N;
    for(int i = 0; i < 101; i++) {
        v.push_back(i*i);
    }
    for(auto &ele : v) {
        if((ele >= M) && (ele <= N)) {
            if(min > ele) {
                min = ele;
            }
            sum += ele;
        }
    }
    if(sum == 0) {
        cout << -1 << "\n";
        return 0;
    }
    cout << sum << "\n" << min << "\n";
    return 0;
}