#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int vis[N];
int a[N];
int n,m;
int check(int mid)
{ 
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]<=mid)
        {
            ans+=(mid-vis[i])/2;
        }
        else 
        {
            ans-=(vis[i]-mid);
        }
    }
    if(ans>=0)return 1;
    else return 0;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        vis[i]=0;
    for(int i=1;i<=m;i++)cin>>a[i],vis[a[i]]++;
        int l=1,r=m*2,ans=r;
    while(l<r-1)
    {
        int mid=(l+r)>>1;
        if(check(mid))ans=mid,r=mid;
        else l=mid;
    }
    if(check(ans-3))cout<<ans-3<<endl;
    else if(check(ans-2))cout<<ans-2<<endl;
    else if(check(ans-1))cout<<ans-1<<endl;
    else cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}