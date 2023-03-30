/** 이 문제는 벡터가 배열보다 일반적으로 10배정도 느리다.라는 것을 알게 되었다. **/
/** 그리고 이분탐색을 써야 한다. 이분탐색을 쓰면 시간복잡도가 logN으로 준다. **/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FindNum(int target, int num, int table[]);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    int input;
    // vector<int> sorted_table;

    // N 입력
    cin >> N;
    int *table = new int[N+1];

    // 원소들을 오름차순으로 정렬 입력
    for(int i = 0; i < N; i++) {
        cin >> table[i];
        // table.push_back(input);
    }
    sort(table, table + N);

    // M 입력
    cin >> M;

    // M번동안 입력받은 숫자에 대해서 sorted_table에 있는지 판단
    for(int i = 0; i < M; i++) {
        cin >> input;
        cout << FindNum(input, N, table) << "\n";
    }

    return 0;
}
int FindNum(int target, int num, int table[])
{
    int low = 0;
    int high = num - 1;
    int mid = (low + high) / 2;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(table[mid] == target) {
            return 1;
        }
        else if(table[mid] > target)
        {
            high = mid - 1;
        }
        else if(table[mid] < target)
        {
            low = mid + 1;
        }
    }
    return 0;
}