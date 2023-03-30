// <직사각형에서 탈출>
// 입력 : 첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.
// 출력 : 첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.

// <알고리즘>
// 8x8짜리를 checkErrorNum으로 (M-7) x (N-7)번 검사 후 최소값 출력

#include <iostream>

using namespace std;

int main()
{
    int x, y, w, h;
    int x_dist, y_dist;
    cin >> x >> y >> w >> h;

    if(w/2 < x)
    {
        x_dist = w - x;
    }
    if(w/2 >= x)
    {
        x_dist = x;
    }
    if(h/2 < y)
    {
        y_dist = h - y;
    }
    if(h/2 >= y)
    {
        y_dist = y;
    }

    if(x_dist < y_dist)
    {
        cout << x_dist << endl;
    }
    else
    {
        cout << y_dist << endl;
    }

    return 0;
}