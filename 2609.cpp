#include <iostream>

using namespace std;

int FindGCD(int& num1, int& num2);
int FindLCM(int& num1, int& num2);

int main()
{
    int num1, num2;
    cin >> num1 >> num2;

    cout << FindGCD(num1, num2) << endl;
    cout << FindLCM(num1, num2) << endl;
    return 0;
}
int FindGCD(int& num1, int& num2)
{
    int min;
    int GCD;
    if(num1 >= num2)
    {
        min = num2;
    }
    else
    {
        min = num1;
    }
    for(int i = min; i > 0; i--)
    {
        if((num1%i == 0) && (num2%i == 0))
        {
            GCD = i;
            break;
        }
    }
    return GCD;
}
int FindLCM(int& num1, int& num2)
{
    int LCM = num1 * num2 / FindGCD(num1, num2);
    return LCM;

}