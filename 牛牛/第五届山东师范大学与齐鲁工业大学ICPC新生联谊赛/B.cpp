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
const int maxn=3e6+100;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int max_dep=-1,root;
int vis[maxn];
int f[maxn];
vector<int>li;
int n,P;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dfs1(int x,int dep,int fa=0)
{
	if(dep>max_dep){
		max_dep=dep;
		root=x;
	}
	for(int i=head[x];i;i=edge[i].next){
		int y=edge[i].to;
		if(y==fa)continue;
		dfs1(y,dep+1,x);
	}
}
void dfs2(int x,int c,int fa=0)
{
	f[x]=fa;
	// cout<<x<<" "<<c<<endl;
	if(vis[c]){
		li.push_back(vis[c]);
		li.push_back(x);
		return ;
	}
	vis[c]=x;
	if(li.size())return ;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w=edge[i].w;
		if(y==f[x])continue;
		int _c=(c+w)%P;
		dfs2(y,_c,x);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	cin>>P;
	dfs1(1,0);
	dfs2(root,0);

	int s=li[1],t=li[0];
	vector<int>ans;
	while(s!=t)
	{
		ans.push_back(s);
		s=f[s];
	}
	ans.push_back(t);
	cout<<ans.size()<<endl;
	for(auto i:ans)
		cout<<i<<" ";cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}