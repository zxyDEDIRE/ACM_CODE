#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ft first
#define sd second
#define endl '\n'
#define int long long
#define iit __int128_t
using namespace std;
typedef pair<int,int>pii;
const double pi=acos(-1.0);//圆周率
const double eps=1e-7;
const int N=5e3+5;

/********************************************************************************************/

int n,m,k,s,t;
int dis[N][520];
struct lol{
    int y,w,id;
};
vector<lol>e[N];
struct pos{
    int now,f,cnt;
};
void bfs(){
    for(int i=1;i<=n;++i)
        for(int j=0;j<520;++j)
            dis[i][j]=1e18;
    //for(int j=0;j<520;++j)dis[s][j]=0;
    dis[s][0]=0;
    queue<pos>q;
    q.push({s,0,0});
    while(q.size()){
        auto [now,f,cnt]=q.front();q.pop();
        if(cnt>dis[now][f])continue;
        for(auto [nex,w,id]:e[now]){
            int tmp=(f|(1ll<<id));
            if(dis[nex][tmp]>cnt+w){
                dis[nex][tmp]=cnt+w;
                q.push({nex,tmp,cnt+w});
            }
        }
    }
}
void solve(){
    cin>>n>>m>>k>>s>>t;
    for(int i=1;i<=m;++i){
        int x,y,w,op;
        cin>>x>>y>>w>>op;
        e[x].push_back({y,w,op});
        e[y].push_back({x,w,op});
    }
    bfs();
    int q;cin>>q;
    while(q--){ 
        int x;cin>>x;
        int res=0;
        for(int i=1;i<=x;++i){
            int y;cin>>y;
            res=(res|(1ll<<y));
        }
        int ans=1e18;
        for(int i=0;i<520;++i)
            if((i&res)==0)
                ans=min(ans,dis[t][i]);
        if(ans==1e18)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}
signed main(){
    IOS;
    int _=1;
    //cin>>_;
    while(_--)
    solve();
    return 0;
}