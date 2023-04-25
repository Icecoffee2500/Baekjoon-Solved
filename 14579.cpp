#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

int main() {
    int a, b;
    cin >> a >> b;

    cpp_int ans = 1;
    cpp_int mod = 14579;

    for (int i = a; i <= b; i++) {
        cpp_int temp = 0;
        for (int j = 1; j <= i + 1; j++) {
            temp += j;
        }
        ans *= temp;
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}
