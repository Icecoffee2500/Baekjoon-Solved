#include <iostream>
#include <vector>

using namespace std;

vector<int> findBodyRank(vector<pair<int, int>> body);

int main()
{
    int num, input_x, input_y;
    vector<pair<int, int>> body;
    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> input_x >> input_y;
        body.push_back(make_pair(input_x, input_y));
    }

    vector<int> Rank = findBodyRank(body);
    for(const auto &ele : Rank) {
        cout << ele << " ";
    }
    cout << "\n";

    return 0;
}

vector<int> findBodyRank(vector<pair<int, int>> body)
{
    vector<int> rank;
    for(int i = 0; i < body.size(); i++) {
        rank.push_back(1);
    }

    for(int i = 0; i < body.size(); i++) {
        for(int j = i + 1; j < body.size(); j++) {
            // if(i == j) continue;
            if( (body.at(i).first > body.at(j).first) && ((body.at(i).second > body.at(j).second)) ) {
                rank.at(j)++;
            }
            if ( (body.at(i).first < body.at(j).first) && ((body.at(i).second < body.at(j).second)) ) {
                rank.at(i)++;
            }
        }
    }

    return rank;
}