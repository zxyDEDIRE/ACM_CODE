#include<bits/stdc++.h>
using namespace std;
const int N=2e7+100,M=1e5+10;;
int q[M],c;
bool vis[M];
void init(int n=M-10){
    vis[1]=true;
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            q[c++]=i;
        }
        for(int j=0;1ll*q[j]*i<=n;j++){
            int nu=q[j]*i;
            vis[nu]=true;
            if(i%q[j]==0){
                break;
            }
        }
    }
}
int n;
int head[N],ne[N],to[N],ct=1;
void add(int v,int u)
{
    ne[++ct]=head[v];
    head[v]=ct;
    to[ct]=u;
}
int dfn[M],low[M],p;
int st[M],tp;
int tot[M],cnt;
bool in[M];
int ans[M],to1;
void tanjan(int now,int old)
{

    dfn[now]=++p;
    low[now]=dfn[now];
    st[++tp]=now;
    in[now]=true;
    for(int i=head[now];~i;i=ne[i])
    {
        int v=to[i];
        if(!dfn[v])
        {
            tanjan(v,i);
            low[now]=min(low[now],low[v]);
        }
        else if(i!=(old^1)&&in[v]&&dfn[v]<dfn[now]) {
            low[now]=min(low[now],dfn[v]);
        }
    }
    if(low[now]==dfn[now])
    {
        ++cnt;
        int x;
        do
        {
            x=st[tp--];
            ans[++to1]=x;
            tot[x]=cnt;
            in[x]=false;
        }while(x!=now);
    }
}

void solve(){
    cin>>n;
    init(n);
    for(int i=1;i<=n;i++){
        head[i]=-1;
    }
    for(int i=1;i<=n;i++){

        for(int j=i+2;j<=min(i+400,n);j++){
            if(vis[abs(i-j)]==false){
                add(i,j);add(j,i);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0) {
            tanjan(i,0);
        }
    }
    if(cnt==1){
        for(int i=1;i<=to1;i++) cout<<ans[i]<<" ";
    }
    else{
        cout<<"-1\n";
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
