#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main()
{
    int N;
    int input;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        pq.push(input);
    }

    while(!pq.empty())
    {
        cout << pq.top() << "\n";
        pq.pop();
    }
    return 0;
}