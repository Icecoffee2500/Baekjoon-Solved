#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

string make_sequence(int num);

int main()
{
    int num;
    cin >> num;

    cout << make_sequence(num) << endl;;
    
    return 0;
}

string make_sequence(int num)
{
    int *arr = new int[num]; // 동적 할당
    stack<int> stk;
    queue<int> que;

    string how_to_make = "+\n";

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
        que.push(i+1);
    }
    stk.push(que.front());
    que.pop();

    for(int i = 0; i < num; i++)
    {
        while(1)
        {
            if (stk.empty() || arr[i] > stk.top())
            {
                how_to_make += "+\n";
                stk.push(que.front());
                que.pop();
            }
            else if(arr[i] == stk.top())
            {
                how_to_make += "-\n";
                stk.pop();
                break;
            }
            else
            {
                delete[] arr; // 동적 할당 해제
                return "NO";
            }
        }
    }

    delete[] arr; // 동적 할당 해제
    return how_to_make;
}