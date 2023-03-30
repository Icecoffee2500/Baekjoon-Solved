#include <iostream>
#include <vector>

using namespace std;

void EratoPrime(int num, vector<bool>& v);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, input;
    int count = 0;
    cin >> N;

    vector<bool> is_prime(1001, true);
    is_prime[0] = false;
    is_prime[1] = false;

    EratoPrime(1000, is_prime);

    for(int i = 0; i < N; i++)
    {
        cin >> input;
        if(is_prime[input] == true)
        {
            count++;
        }
    }
    cout << count << "\n";

    return 0;
}
void EratoPrime(int num, vector<bool>& v)
{
    for(int i = 2; i*i <= num; i++)
    {
        if(v[i] == true)
        {
            for(int j = i*i; j <= num; j += i)
            {
                v[j] = false;
            }
        }
    }
}