// <체스판 다시 칠하기>
// 입력 : 첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.
// 출력 : 첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.

// <알고리즘>
// 8x8짜리를 checkErrorNum으로 (M-7) x (N-7)번 검사 후 최소값 출력

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int checkErrorNum(int **table, int row, int col);

int main()
{
    // 정사각형의 개수 입력 및 테이블 생성
    int M, N;
    int min = 65;
    int error_num;
    cin >> M >> N;
    int **table = new int*[M];
    for(int i = 0; i < M; i++)
    {
        table[i] = new int[N];
    }
    cin.ignore();

    // table 입력
    string temp;
    for(int i = 0; i < M; i++)
    {
        getline(cin, temp);
        for(int j = 0; j < N; j++)
        {
            if(temp[j] == 'B')
            {
                table[i][j] = 0;
            }
            else if(temp[j] == 'W')
            {
                table[i][j] = 1;
            }
        }
    }

    // 룹 돌면서 검사
    for(int i = 0; i < M-7; i++)
    {
        for(int j = 0; j < N-7; j++)
        {
            error_num = checkErrorNum(table, i, j);
            if(error_num > 32)
            {
                error_num = 64 - error_num;
            }
            if (min > error_num)
            {
                min = error_num;
            }
        }
    }

    // 동적할당 해제
    for(int i = 0; i < M; i++) {
        delete[] table[i];
    }
    if(table != NULL)
    {
        delete[] table;
    }
    
    cout << min << endl;

    return 0;
}

int checkErrorNum(int **table, int row, int col)
{
    int count = 0;
    bool std = table[row][col];
    for(int i = row; i < (row + 8); i++)
    {
        for(int j = col; j < (col + 8); j++)
        {
            if((j-col)%2 == 0 && std != table[i][j])
            {
                count++;
            }
            if((j-col)%2 == 1 && std == table[i][j])
            {
                count++;
            }
        }
        std = !(std);
    }
    return count;
}