#include <iostream>

using namespace std;

int testPopulation(int p, int t);

int main()
{
    int case_num;
    cin >> case_num;
    int table[case_num+1];
    for(int i = 0; i < case_num; i++) {
        int a, b;
        cin >> a >> b;
        table[i] = testPopulation(a, b);
    }
    for(int i = 0; i < case_num; i++) {
        cout << table[i] << "\n";
    }
    return 0;
}

int testPopulation(int p, int t)
{
    int result = 0;
    result = p + t/4 - t/7;
    return result;
}