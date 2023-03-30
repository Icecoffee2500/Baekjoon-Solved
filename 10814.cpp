#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int N;
    int input_num;
    string input_str;
    cin >> N;
    string table[N+1];

    for(int i = 0; i < N; i++) {
        cin >> input_num;
        pq.emplace(input_num, i);
        cin >> table[i];
    }

    for(int i = 0; i < N; i++) {
        cout << pq.top().first << " " << table[pq.top().second] << "\n";
        pq.pop();
    }

    return 0;
}