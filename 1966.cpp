#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int case_num, count;
    cin >> case_num;
    int result[case_num + 1];

    // test case의 수만큼 반복
    for(int i = 0; i < case_num; i++) {
        priority_queue<int> pq;
        queue<pair<int, int>> queue;
        int page_num, q_idx;
        count = 0;
        cin >> page_num >> q_idx; // 문서갯수, 타겟 인덱스

        // 문서의 개수만큼 반복하면서 문서의 우선순위 및 인덱스 저장
        for(int j = 0; j < page_num; j++) {
            int input;
            cin >> input;
            queue.push({j, input}); // {인덱스, 우선순위} 저장
            pq.push(input); // 우선순위 저장 및 정렬
        }
        while(!queue.empty()) {
            int location = queue.front().first;
            int value = queue.front().second;
            queue.pop();

            if(pq.top() == value) {
                pq.pop();
                ++count;
                if(q_idx == location) {
                    result[i] = count;
                    break;
                }
            }

            else {
                queue.push({location, value});
            }
        }
    }

    for(int i = 0; i < case_num; i++) {
        cout << result[i] << "\n";
    }

    
    return 0;
}