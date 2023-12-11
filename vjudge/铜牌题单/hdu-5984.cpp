#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
#define int long long
typedef long long ll;
typedef pair<int,int> P;
const int N=2e5+7;
const int INF=0x3f3f3f3f;
const int mod=998244353;
int n,m,s;
struct Edge
{
    int to,next,w;
}e[N];
int head[N],cnt;
void add(int from,int to,int w)
{
    e[++cnt].w=w;
    e[cnt].to=to;
    e[cnt].next=head[from];
    head[from]=cnt;
}
int dis[N],vis[N];
void spfa()
{
    queue<int>q;
    memset(dis+1,INF,sizeof(int)*n);
    memset(vis+1,0,sizeof(int)*n);
    q.push(s);
    dis[s]=0;
    vis[s]=1;
    while(q.size()){
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x];i;i=e[i].next){
            int y=e[i].to;
            int w=e[i].w;
            if(dis[y]>dis[x]+w){
                dis[y]=dis[x]+w;
                if(!vis[y]){
                    vis[y]=1;
                    q.push(y);
                }
            }
        }
    }
}
void solve()
{
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    spfa();
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}
signed main()
{
    IOS
    int __=1;
    //cin >> __;
    while (__--)
        solve();
}