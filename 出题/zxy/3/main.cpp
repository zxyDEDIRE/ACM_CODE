#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=1e5+100;
struct node{
	int id,op; ll dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w,op;
}edge[maxn];
int head[maxn],cnt;
ll dis[N][500];
bool vis[N][500];
int n,m,k,s,t,q;
inline void add(int from,int to,int w,int op){
	edge[++cnt].w=w;
	edge[cnt].op=op;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij()
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<=(1<<k);j++)
			dis[i][j]=INF;
	dis[s][0]=0;
	priority_queue<node>q;
	q.push({s,0,0});
	while(!q.empty())
	{
		auto [x,fl,DIS]=q.top();q.pop();
		if(vis[x][fl])continue;
		vis[x][fl]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			ll w=edge[i].w;
			int op=(edge[i].op|fl);
			if(dis[y][op]>dis[x][fl])
			{
				dis[y][op]=dis[x][fl]+w;
				q.push({y,op,dis[y][op]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>k>>s>>t;
	int T=(1<<k)-1;
	// cout<<n*T<<" "<<T<<endl;
	for(int i=1;i<=m;i++)
	{
		int op,x,y,w;
		cin>>x>>y>>w>>op;op--;
		add(x,y,w,1<<op);
		add(y,x,w,1<<op);
	}
	dij();
	for(int i=1;i<(1<<k);i++)
		for(int j=i+1;j<(1<<k);j++)
			if((i&j)==i){
				for(int k=1;k<=n;k++)
					dis[k][j]=min(dis[k][i],dis[k][j]);
			}


	cin>>q;
	while(q--)
	{
		int num,fl=0,x;
		cin>>num;
		while(num--){
			cin>>x;x--;
			fl|=(1<<x);
		}
		// cout<<t<<" "<<(T^fl)<<" "<<fl<<endl;
		if(dis[t][T^fl]==INF)cout<<-1<<endl;
		else cout<<dis[t][T^fl]<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
4 5 3 1 4
1 2 5 1
1 3 3 1
2 4 6 2
3 4 1 2
1 4 10 3
3
1 1
1 2
1 3
*/