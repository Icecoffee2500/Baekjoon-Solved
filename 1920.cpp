#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

bool FindNum(int target, int num, vector<int> v);

int main()
{
    int N, M;
    int input;
    priority_queue<int> A;
    vector<int> sorted_table;
    string str = "";

    // N 입력
    cin >> N;

    // 원소들의 정렬을 위해 Priority Queue에 Push
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        A.push(input);
    }
    // 정렬된 Priority Queue의 원소들을 탐색을 위해 Vector로 옮김
    for(int i = 0; i < N; i++)
    {
        sorted_table.push_back(A.top());
        A.pop();
    }

    // M 입력
    cin >> M;

    // M번동안 입력받은 숫자에 대해서 sorted_table에 있는지 판단
    for(int i = 0; i < M; i++)
    {
        cin >> input;
        if(FindNum(input, N, sorted_table))
        {
            str += "1\n";
        }
        else
        {
            str += "0\n";
        }
    }

    cout << str;

    return 0;
}
bool FindNum(int target, int num, vector<int> v)
{
    int min = 0;
    int max = num - 1;
    int avg = (min + max) / 2;

    while(1)
    {
        cout << "target : " << target << ", max : " << max  << ", min : " << min << ", avg : " << avg << endl;
        if(v.at(avg) > target)
        {
            min = avg;
        }
        else if(v.at(avg) <= target)
        {
            max = avg;
        }
        avg = (min + max) / 2;
        if((avg == min) || (avg == max))
        {
            if(target == v.at(max))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        //cout << "now min is " << min << " and max is " << max << endl;
    }

}