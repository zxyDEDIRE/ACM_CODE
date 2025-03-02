#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
vector<int>v[maxn];
vector<int>p;
int n;
void dfs(int x)
{
    int cnt=v[x].size();
    if(cnt>0)p.push_back(cnt);
    for(int i=0;i<v[x].size();i++)
        dfs(v[x][i]);
}
bool check(int x)
{
    int ans=0;
    for(int i=0;i<p.size();i++)
    {
        if(p[i]>x)ans+=p[i]-x;
        if(x>0)x--;
    }
    if(x>=ans)return 1;
    else return 0;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)v[i].clear();
    for(int i=2,x;i<=n;i++){
        cin>>x;
        v[x].push_back(i);
    }
    p.clear();
    p.push_back(1);
    dfs(1);
    sort(p.begin(),p.end(),[&](int a,int b){return a>b;});
    int l=1,r=n,ans=r;
    while(l<r-1)
    {
        int mid=(l+r)>>1;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid;
    }
    if(check(ans-1))cout<<ans-1<<endl;
    else cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int __;cin>>__;
    while(__--)solve();
}
/*
3 2 1 1
4 3 2 1
*/