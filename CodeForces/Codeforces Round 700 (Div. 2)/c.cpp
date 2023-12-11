/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
signed main()
{
    int n;
    cin >> n;
    int l = 0,r = n-1,no = 0;
    while(l < r)
    {
        int m = (l+r)/2;
        int p[3];
        cout << "? " << m+1 << "\n";
        cout.flush();
        cin >> p[1];
        if(m == 0)
            p[0] = 1000000000000000;
        else
        {
            cout << "? " << m << "\n";
            cout.flush();
            cin >> p[0];

        }
        cout << "? " << m+2 << "\n";
        cout.flush();
        cin >> p[2];
        if(p[1] > p[2])
            l = m+1;
        else if(p[1] > p[0])
            r = m-1;
        else
        {
            no = 1;
            cout << "! " << m+1;
            break;
        }
    }
    if(!no)
        cout << "! " << l+1;

    return 0;
}
