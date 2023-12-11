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
namespace Flow{
	struct Edge{
		int to,next,w;
	}edge[maxn];
	int head[maxn],cnt=1;
	int dep[maxn];
	int now[maxn];
	int s,t,tot;
	void init(){
		memset(head+1,0,sizeof(int)*tot);
		cnt=1;
		tot=0;
	}
	void add(int from,int to,int w)
	{
		edge[++cnt].w=w;
		edge[cnt].to=to;
		edge[cnt].next=head[from];
		head[from]=cnt;
	}
	void Add(int u,int v,int w)
	{
		add(u,v,w);
		add(v,u,0);
	}
	bool bfs(int s,int t)
	{
		for(int i=1;i<=tot;i++)
			dep[i]=INF;
		queue<int>q;
		q.push(s);
		dep[s]=0;
		now[s]=head[s];
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=head[x];i;i=edge[i].next){
				int y=edge[i].to;
				if(edge[i].w>0&&dep[y]==INF){
					q.push(y);
					now[y]=head[y];
					dep[y]=dep[x]+1;
					if(y==t)return 1;
				}
			}
		}
		return 0;
	}
	int dfs(int x,int flow,int t)
	{
		if(x==t)return flow;
		int ans=0,k;
		for(int i=now[x];i&&flow;i=edge[i].next){
			now[x]=i;
			int y=edge[i].to;
			if(edge[i].w>0&&dep[y]==dep[x]+1){
				k=dfs(y,min(flow,edge[i].w),t);
				if(!k)dep[y]=inf;
				edge[i].w-=k;
				edge[i^1].w+=k;
				ans+=k;
				flow-=k;
			}
		}
		return ans;
	}
	int DINIC()
	{
		int ans=0;
		while(bfs(s,t))
			ans+=dfs(s,INF,t);
		return ans;
	}
}
using namespace Flow;
int d[maxn];
pii p[maxn];
int n,m;
vector<int>q;
bool check(int c)
{
	init();
	tot=n;
	s=++tot;
	t=++tot;
	int ano=++tot;
	Add(ano,t,c);
	for(int i=1;i<=n;i++)
	{
		Add(i,t,d[i]);
		Add(i,ano,INF);
	}
	q.clear();
	for(int i=1;i<=m;i++)
	{
		auto [x,y]=p[i];
		tot++;
		Add(s,tot,1);
		Add(tot,x,1);
		Add(tot,y,1);
		q.push_back(tot);
	}
	int ans=DINIC();

	// cout<<endl;
	// for(auto x:q)
	// {
	// 	for(int i=head[x];i;i=edge[i].next)
	// 	{
	// 		int y=edge[i].to;
	// 		if(y>=1&&y<=n&&edge[i].w==0)
	// 			cout<<x<<"->"<<y<<endl;
	// 	}
	// }
	// cout<<"ANS "<<ans<<endl;
	return ans==m;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	for(int i=1;i<=m;i++)
		cin>>p[i].first>>p[i].second;
	int l=0,r=m,ans=m;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	while(ans>0 && check(ans-1))ans--;
	cout<<ans<<endl;
	check(ans);
	vector<int>_q;
	for(auto x:q)
	{
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(y>=1&&y<=n&&edge[i].w==0)
			{
				_q.push_back(y);
				// cout<<x<<"->"<<y<<endl;
			}
		}
	}
	// cout<<"size "<<q.size()<<endl;
	// cout<<"size "<<_q.size()<<endl;
	for(int i=1;i<=m;i++)
	{
		auto [x,y]=p[i];
		int w=_q[i-1];
		if(y==w)cout<<0;
		else cout<<1;
	}
	cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
2
4 5
0 1 1 5
1 2
1 3
2 3
3 2
4 4
3 2
0 0 2
1 3
3 2


1 2
1 3
2 3
3 2
4 4


0221
0115
*/