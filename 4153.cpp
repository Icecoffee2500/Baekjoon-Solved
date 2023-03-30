#include <iostream>
#include <array>

//using namespace std;

int main()
{
    int max;
    int count;
    std::array<int, 3> arr1;
    
    while(1)
    {
        count = 0;
        max = 0;
        for(auto& elem : arr1)
        {
            std::cin >> elem;
            if(max < elem)
            {
                max = elem;
            }
        }
        if(arr1.at(0) == 0 && arr1.at(1) == 0 && arr1.at(2) == 0)
        {
            break;
        }
        for(int i = 0; i < 3; i++)
        {
            if(max != arr1.at(i))
            {
                count += arr1.at(i) * arr1.at(i);
            }
        }

        if(max * max == count)
        {
            std::cout << "right" << std::endl;
        }
        else
        {
            std::cout << "wrong" << std::endl;
        }
    }

    return 0;
}