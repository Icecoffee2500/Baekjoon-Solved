#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    int max;
    int input;
    cin >> num >> max;
    vector<int> sorted_table;

    for(int i = 0; i < num; i++) {
        cin >> input;
        sorted_table.push_back(input);
    }
    sort(sorted_table.begin(), sorted_table.end());

    cout << "sorted : ";
    for(auto ele : sorted_table) {
        cout << ele << " ";
    }
    cout << endl;
    int sum = 0;
    while(sorted_table.size() > 3) {
        sum = 0;
        int center = sorted_table.size()/2;
        sum = sorted_table.at(center) + sorted_table.at(center-1) + sorted_table.at(center+1);
        cout << "center : " << center << ", sum : " << sum << "\n";
        if(sum > max) {
            cout << "pop num : " << sorted_table.size()-center-1 << "\n";
            int iter = sorted_table.size()-center-1;
            for(int i = 0; i < iter; i++) {
                sorted_table.pop_back();
                //cout << "end : " << sorted_table.back() << "\n";
            }
            cout << "HIGH! start : " << sorted_table.at(0) << ", end : " << sorted_table.at(sorted_table.size()-1) << "\n";
        }
        else if(sum < max) {
            for(int i = 0; i < center-1; i++) {
                sorted_table.erase(sorted_table.begin());
            }
            cout << "LOW! start : " << sorted_table.at(0) << ", end : " << sorted_table.at(sorted_table.size()-1) << "\n";
        }
        else {
            break;
        }
    }
    sum = sorted_table.at(0) + sorted_table.at(1) + sorted_table.at(2);
    cout << sum << "\n";

    return 0;
}