/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
ll dp[70][70];
int p[maxn];
ll n,k,t;
void solve()
{
	//cin>>n>>k;
    n=2,k=5;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            
        }
    }
    cout<<dp[n][0]<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}
/*
n k t
2 5 1
0 1 2 3 4

12
2 3
1 4
3 2
4 1
0 1
0 2
0 3
0 4
1 0
2 0
3 0
4 0




*/
