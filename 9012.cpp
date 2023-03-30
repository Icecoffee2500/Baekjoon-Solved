#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string findVPS(string str);

int main()
{
    int num;
    string str;
    vector<string> word;
    cin >> num;
    cin.ignore();

    for(int i = 0; i < num; i++) {
        //getline(cin, str);
        cin >> str;
        word.push_back(str);
        //cout << "hmm...string is " << input[i] << endl;
    }
    for(int i = 0; i < num; i++) {
        //cout << "now string is " << word.at(i) << endl;
        cout << findVPS(word.at(i)) << "\n";
    }

    return 0;
}
string findVPS(string str)
{
    stack<int> st;
    int size = str.length();
    for(int i = 0; i < size; i++) {
        if(str.at(i) == '(') {
            st.push(1);
        }
        else if(str.at(i) == ')') {
            if(!st.empty()) {
                st.pop();
            }
            else {
                return "NO";
            }
        }
    }
    if(!st.empty()) {
        return "NO";
    }
    else {
        return "YES";
    }
}