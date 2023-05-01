#include <iostream>
#include <vector>

using namespace std;

int 영식요금제(vector<int> v);
int 민식요금제(vector<int> v);

int main()
{
    int num;
    vector<int> v;
    cin >> num;

    for(int i = 0; i < num; i++) {
        int sec;
        cin >> sec;
        v.push_back(sec);
    }
    int 영식 = 영식요금제(v);
    int 민식 = 민식요금제(v);

    if(영식 > 민식) {
        cout << "M " << 민식 << "\n";
    }
    else if(영식 < 민식) {
        cout << "Y " << 영식 << "\n";
    }
    else {
        cout << "Y M " << 영식 << "\n";
    }

    return 0;
}

int 영식요금제(vector<int> v)
{
    int result = 0;
    int req = 10;
    int sec = 30;
    for(const auto& ele : v) {
        result += (ele/sec + 1) * req;
    }
    return result;
}
int 민식요금제(vector<int> v)
{
    int result = 0;
    int req = 15;
    int sec = 60;
    for(const auto& ele : v) {
        result += (ele/sec + 1) * req;
    }
    return result;
}