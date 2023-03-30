#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> fifo;
    int input;
    cin >> input;

    for (int i = 1; i <= input; i++) {
        fifo.push(i);
    }
    while(fifo.size() > 1) {
        fifo.pop();
        fifo.push(fifo.front());
        fifo.pop();
    }
    cout << fifo.front() << "\n";
    
    return 0;
}