#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>p1, pair<int, int>p2);

int main()
{
    vector<pair<int, int>> v;
    int count, input1, input2;
    cin >> count;


    for(int i = 0; i < count; i++) {
        cin >> input1 >> input2;
        v.push_back(make_pair(input1, input2));
    }
    sort(v.begin(), v.end(), compare);
    for(const auto &ele : v) {
        cout << ele.first << " " << ele.second << "\n";
    }
    return 0;
}

bool compare(pair<int, int>p1, pair<int, int>p2)
{
    if(p1.second < p2.second) {
        return true;
    }
    if(p1.second == p2.second) {
        if(p1.first < p2.first) {
            return true;
        }
    }
    return false;
}