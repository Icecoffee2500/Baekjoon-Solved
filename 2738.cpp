// <행렬 덧셈>
// 입력은 첫째 줄에 행렬의 크기 N, M // 둘째 줄에 행렬 A의 원소 차례대로 이어서 행렬 B의 원소 차례대로
// 출력은 더해진 행렬

#include <iostream>

using namespace std;

void inputToMatrix(int** arr, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
}

int main()
{
    // 변수 생성 후 입력받기
    int N, M;
    cin >> N >> M;
    
    // 행렬 A, B 생성
    int **A = new int *[N];
    int **B = new int *[N];
    for(int i = 0; i < N; i++)
    {
        A[i] = new int[M];
        B[i] = new int[M];
    }

    // 행렬 A, B 입력 받기
    inputToMatrix(A, N, M);
    inputToMatrix(B, N, M);

    // 출력
    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << A[i][j] + B[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < N; i++)
    {
        delete[] A[i];
        delete[] B[i];
    }
    delete[] A;
    delete[] B;

    return 0;

}