#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e5;
const int N=1e3;
vector<int>v[maxn];
bitset<maxn>vis;
int p[maxn][2];
int n,ans;
void dfs(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        int y=v[x][i];
        dfs(y);
        p[x][0]+=p[y][0];
        p[x][1]+=p[y][1];
    }
    p[x][vis[x]]++;
    if(p[x][0]==p[x][1])ans++;
}
void solve()
{
    cin>>n;
    vis.reset();
    for(int i=1;i<=n;i++)
        p[i][0]=p[i][1]=0,v[i].clear();
    for(int i=2,x;i<=n;i++){
        cin>>x;
        v[x].push_back(i);
    };
    for(int i=1;i<=n;i++){
        char ch;cin>>ch;
        if(ch=='B')vis[i]=1;
    }
    ans=0;
    dfs(1);
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int __;
    cin>>__;
//  __=1;
    while(__--)solve();
}