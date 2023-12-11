#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int pa[N*31][2],idx;
int ans[N];
int a[N];
void insert(int k)
{
    int p=0;
    for(int i=30;i>=0;i--)
    {
        int u=k>>i&1;
        if(!pa[p][u]) pa[p][u]=++idx;
        p=pa[p][u];
    }
    //ans[p]++;
}
int query(int k)
{
    int p=0;
    int res=0;
    for(int i=30;i>=0;i--)
    {
        int u=k>>i&1;
        if(pa[p][!u]) p=pa[p][!u],res=res*2+!u;
        else p=pa[p][u],res=res*2+u;
    }
    res^=k;
    return res;
}
int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        insert(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,query(a[i]));
    }
    cout<<ans<<endl;
}