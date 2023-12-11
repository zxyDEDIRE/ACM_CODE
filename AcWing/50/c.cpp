#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1000;
ll dp[maxn][maxn];
ll p[maxn];
ll n,k,x;

int main()
{
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int t=1;t<=x;t++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=max(0ll,i-k);j<i;j++)
            {
            	dp[i][t]=max(dp[i][t],dp[j][t-1]+p[i]);
            }
        }
    }
    ll res = -1;
    for(int i=n-k+1;i<=n;i++) res = max(res , dp[i][x]);
    cout<<res<<endl;
}