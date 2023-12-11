#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 110;
int n, k;
int a[N];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    sort(a, a + k);
    int s = 0, res = 0;
    for (int i = 0; i < k; i ++ ) s += a[i];
    for (int i = k; i < n; i ++ )
    {
        if (a[i] < a[0])
        {
            res ++;
            s += a[i] - a[0];
            int j = 1;
            while (j < k && a[j] <= a[i]) j ++ ;
            for (int t = 0; t < j - 1; t ++ ) a[t] = a[t + 1];
            a[j - 1] = a[i];
        } 
    }
    cout << (s - res) << endl;
    return 0;
}
