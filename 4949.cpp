#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isGood(string str);

int main()
{
    string str;
    vector<string> answer;
    while(1) {
        getline(cin, str);
        if(str == ".") {
            break;
        }
        if(isGood(str)) {
            answer.push_back("yes");
        }
        else {
            answer.push_back("no");
        }
    }
    for(const auto &ele : answer) {
        cout << ele << "\n";
    }
    return 0;
}

bool isGood(string str)
{
    vector<int> stack;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            stack.push_back(0);
        }
        if(str[i] == ')') {
            if(stack.empty()) {
                return false;
            }
            if(stack.back() != 0) {
                return false;
            }
            stack.pop_back();
        }
        if(str[i] == '[') {
            stack.push_back(1);
        }
        if(str[i] == ']') {
            if(stack.empty()) {
                return false;
            }
            if(stack.back() != 1) {
                return false;
            }
            stack.pop_back();
        }
    }
    if(!stack.empty()) {
        return false;
    }
    return true;
}