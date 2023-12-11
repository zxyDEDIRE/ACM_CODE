#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> D(N);
    for (auto &&d : D)
        cin >> d;

    int ans = 0;
    for (int m = 1; m <= N; ++m) {
        string month = to_string(m);
        for (int d = 1; d <= D[m - 1]; ++d) {
            string date = month + to_string(d);
            if (size(set<char>(date.begin(), date.end())) == 1)
                ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}
