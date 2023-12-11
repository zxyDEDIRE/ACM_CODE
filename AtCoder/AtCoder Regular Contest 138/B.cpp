#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int n, k;
int a[N];
int calc()
{
    int s = 0;
    for (int i = 0; i < k; i ++ ) s += a[i];
    return s;
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    sort(a, a + k);
    int res = calc();
    for (int i = k; i < n; i ++ )
    {
        int cnt = 0;
        for (int j = k; j < n - cnt; j ++ )
            if (a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
                cnt ++ ;
                if (calc() > res)
                {
                    cout << cnt << endl;
                    return 0;
                }
            }
    }
    puts("-1");
    return 0;
}