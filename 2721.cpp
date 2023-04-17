#include <iostream>

using namespace std;

int WeightedSum(int n);
int Tree(int k);

int main()
{
    int input, count;
    cin >> count;
    for(int i = 0; i < count; i++) {
        cin >> input;
        cout << WeightedSum(input) << "\n";
    }
    return 0;
}

int WeightedSum(int n)
{
    int sum = 0;
    for(int k = 1; k <= n; k++) {
        sum += k * Tree(k+1);
    }
    return sum;
}
int Tree(int k)
{
    return k * (k+1) / 2;
}