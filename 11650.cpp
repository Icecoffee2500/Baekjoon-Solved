#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<pair<int, int>> container;
    int num;
    int x, y;
    cin >> num;

    for(int i = 0; i < num; i++) {
        cin >> x >> y;
        container.push_back(make_pair(x, y));
    }

    sort(container.begin(), container.end());

    for(auto &ele : container) {
        cout << ele.first << " " << ele.second << "\n";
    }

    return 0;
}