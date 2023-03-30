#include <iostream>
#include <string>

using namespace std;

void dec_palindrome(string str);

int main()
{
    string number;
    while(1)
    {
        getline(cin, number);
        if(number.front() == '0')
        {
            break;
        }
        dec_palindrome(number);
    }

    return 0;
}
void dec_palindrome(string str)
{
    string temp = "";
    for(int i = str.size()-1; i >= 0; i--)
    {
        temp = temp + str.at(i);
    }
    if(temp == str)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return;
}