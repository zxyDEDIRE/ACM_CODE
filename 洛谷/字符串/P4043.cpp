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
	int to,next,w,id;
}edge[maxn];
int head[maxn],cnt;
struct node{
	int x,y,w,op;
}p[maxn];
vector<pii>v[maxn];
int in[maxn];
vector<int>st;
int n,ans;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].id=cnt;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
	p[cnt]={from,to,w,0};
	v[to].push_back({from,cnt});
}
void topsort()
{
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		st.push_back(x);
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			in[y]--;
			if(!in[y])q.push(y);
		}
	}
}
struct Node{
	int id,dis;
	bool operator<(const Node&a)const{
		return a.dis<dis;
	}
};
bool vis[maxn];
int dis[maxn];
pii to[maxn];
void run()
{
	for(int i=1;i<=n;i++)
		dis[i]=INF,vis[i]=0;
	priority_queue<Node>q;
	dis[1]=0;
	q.push({1,0});
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			int id=edge[i].id;
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				to[y]={x,id};
			}
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k,x,w;cin>>k;
		while(k--){
			cin>>x>>w;
			add(i,x,w);
			in[x]++;
		}
	}
	topsort();
	reverse(st.begin(),st.end());
	run();
	for(int i=1;i<=n;i++)
		vis[i]=0;
	for(auto x:st)
	{
		for(auto [y,id]:v[x])
		{
			if(p[id].op==1)continue;
			// cout<<"que "<<y<<" "<<p[id].w<<endl;
			ans+=p[id].w;
			p[id].op=1;

			ans+=dis[y];
			if(!vis[y])
			{
				vis[y]=1;
				int now=y;
				while(now!=1)
				{
					auto [x,id]=to[now];
					p[id].op=1;
					now=x;
				}
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}