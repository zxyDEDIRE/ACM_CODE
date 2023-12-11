#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dfn[maxn],low[maxn],indx,tot;
bool vis[maxn];
stack<int>s;
int ans=INF;
int n,m;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(dfn[x]<low[y])
				ans=min(ans,max(1,edge[i].w));
		}
		else if(i!=(fa^1)&&vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x]){
		tot++;
		int y;
		do{
			y=s.top();s.pop();
			vis[y]=0;
		}while(x!=y);
	}
}
void solve()
{
	cnt=1;
	tot=indx=0;
	for(int i=1;i<=n;i++)
	{
		head[i]=0;
		dfn[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	ans=INF;
	for(int i=1;i<=n;i++)
		if(!dfn[i]){
			if(i!=1)ans=0;
			tarjan(i,0);
		}
	if(ans==INF)ans=-1;
	cout<<ans<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n>>m&&n!=0)
		solve();
	return 0;
}
/*
3 4
1 2 1
2 3 1
1 2 1
2 3 1
0 0
*/