#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tree_num, tree_length; // 나무 개수, 나무 길이 선언
    int max_height = 0; // 나무  최대 선언
    int min_height = 0; // 나무 최소 선언
    int good_height;
    vector<int> tree;
    cin >> tree_num >> tree_length;
    for(int i = 0; i < tree_num; i++) {
        int input;
        cin >> input;
        tree.push_back(input);
        if(max_height < input) {
            max_height = input;
        }
    }
    long long sum = 0;
    
    // cout << max_height << " " << min_height << "\n";
    while(min_height + 1 < max_height) {
        sum = 0;
        int avg_height = (max_height + min_height) / 2;
        // cout << "max : " << max_height << ", min : " << min_height << ", avg : " << avg_height << "\n";
        int h = avg_height;
        for(auto &ele : tree) {
            if(ele > h) {
                sum += (ele - h);
            }
        }
        // cout << "sum : " << sum << ", tree_length : " << tree_length << "\n";
        if(sum >= tree_length) {
            min_height = avg_height;
        }
        if(sum < tree_length) {
            max_height = avg_height;
        }
    }
    sum = 0;
    for(auto &ele : tree) {
        if(ele > max_height) {
            sum += (ele - max_height);
        }
    }
    if(sum >= tree_length) {
        good_height = max_height;
    }
    else {
        good_height = min_height;
    }

    cout << good_height << "\n";
    return 0;
}