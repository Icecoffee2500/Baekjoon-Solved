#include <iostream>
#include <climits>

using namespace std;

void FindMaxLength(int K, int N, long table[], long max);

int main()
{
    long max_length_of_fiber = 1;
    int K, N;
    cin >> K >> N;

    long table[K];
    for(auto& elem : table)
    {
        cin >> elem;
        if(elem > max_length_of_fiber)
        {
            max_length_of_fiber = elem;
        }
    }

    FindMaxLength(K, N, table, max_length_of_fiber);

    return 0;
}

void FindMaxLength(int K, int N, long table[], long max)
{
    long min = 0;
    long walker = (min + max) / 2;
    long sum = 0;
    max *= 2;

    while(1)
    {
        sum = 0;
        for(int i = 0; i < K; i++)
        {
            if(walker == 0)
            {
                walker++;
            }
            sum += table[i] / walker;
        }
        
        
        if(sum < N)
        {
            max = walker;
        }
        else if(sum >= N)
        {
            min = walker;
        }
        walker = (min + max) / 2;

        if((max == walker) || (min == walker))
        {
            break;
        }
        
    }
    
    cout << walker << endl;
    return;
}