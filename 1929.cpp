#include <iostream>
#include <vector>

using namespace std;

void EratoPrime(int num, vector<bool>& v);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<bool> is_prime(N+1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    EratoPrime(N, is_prime);

    for(int i = M; i <= N; i++)
    {
        if(is_prime[i] == true)
        {
            cout << i << "\n";
        }
    }

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