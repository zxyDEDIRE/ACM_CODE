/*
10011001
01100110
01100110
10011001
10011001
01100110
01100110
10011001



10011001
01100110
01100110
10011001
10011001
01100110
01100110
10011001
*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "1" << endl;
        return 0;
    }
    else if (n == 1) {
        cout << "10\n01\n";
        return 0;
    }
    int tot = 1;
    for (int i = 1; i <= n; i ++) {
        tot *= 2;
    }
    string s1, s2;
    s1 += "1"; s2 += "0";
    for (int i = 1, f = 1; i < tot - 1; i +=2) {
        if (f) {
            s1 += "00";
            s2 += "11";
        }
        else {
            s1 += "11";
            s2 += "00";
        }
        f = !f;
    }
    s1 += "1"; s2 += "0";
    cout << s1 << endl;
    for (int i = 1, f = 0; i < tot - 1; i += 2) {
        if (f) cout << s1 << endl << s1 << endl;
        else cout << s2 << endl << s2 << endl;
        f = !f;
    }
    cout << s1 << endl;
    return 0;
}