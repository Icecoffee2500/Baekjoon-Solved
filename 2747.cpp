#include <iostream>

using namespace std;

int fib(int n);


int main()
{
    int input;
    cin >> input;

    cout << fib(input) << endl;
    return 0;
}
int fib(int n) {
    /* if(n == 1)  return 1;
    if(n == 2)  return 1;
    if(mem[n] != 0) return mem[n];

    return fib(n-2) + fib(n-1); */

    int mem[100];

    mem[0] = 0;
    mem[1] = 1;
    for(int i = 2; i <= n; i++) {
        mem[i] = mem[i-1] + mem[i-2];
    }
    return mem[n];

}