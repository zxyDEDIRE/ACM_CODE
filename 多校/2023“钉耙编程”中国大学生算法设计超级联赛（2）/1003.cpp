/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
struct Edge{int to,next;}edge[maxn];
int head[maxn],cnt=1;
vector<int>v[maxn];
int low[maxn],dfn[maxn],indx;
int col[maxn],tot;
int b[maxn];
int a[maxn];
stack<int>s;
int n,m,k,bcc,MID;
void init()
{
	memset(head+1,0,sizeof(int)*n);
	while(s.size())s.pop();
	cnt=1;
	bcc=n;
}
void add(int from,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				bcc++;
				v[bcc].push_back(x);
				v[x].push_back(bcc);
				int u;
				do{
					u=s.top();s.pop();
					v[bcc].push_back(u);
					v[u].push_back(bcc);
				}while(u!=y);
			}
		}
		else if((fa^1)!=i)
			low[x]=min(low[x],dfn[y]);
	}
}
int p[maxn];
int dep[maxn];
int f[maxn][24];
bitset<maxn>vis;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void dfs(int x,int fa)
{	
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=20;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(auto y:v[x])
		if(y!=fa&&b[y]>MID){
			int fa=find(x);
			int fb=find(y);
			if(fa!=fb)p[fa]=fb;
			dfs(y,x);
		}
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for (int j = 0, d = dep[x] - dep[y]; d; ++j, d >>= 1)
		if (d & 1) x = f[x][j];
	if(x==y)return x;
	for (int j = 20; ~j; --j)
		if (f[x][j] != f[y][j])
			x = f[x][j], y = f[y][j];
	return f[x][0];
}
bool check(int mid)
{
	MID=mid;
	vis.reset();
	for(int i=1;i<=bcc;i++)
		p[i]=i;
	for(int i=1;i<=bcc;i++)
	{
		if(vis[i]||b[i]<=MID)continue;
		dfs(i,0);
	}
	vector<int>q;
	for(int i=mid+1;i<=k;i++)
		q.push_back(a[i]);
	sort(q.begin(),q.end(),[&](int a,int b){
		return dfn[a]<dfn[b];
	});
	int lca=-1;
	for(auto i:q)
		cout<<i<<" ";cout<<endl;
	for(int i=1;i<q.size();i++)
	{
		int fa=find(q[i]);
		int fb=find(q[i-1]);
		cout<<"FA "<<fa<<" "<<fb<<endl;
		if(fa!=fb)continue;
		int now=LCA(q[i],q[i-1]);
		// cout<<"A "<<q[i]<<" "<<q[i-1]<<" "<<now<<" "<<lca<<endl;
		if(now!=lca&&lca!=-1)return 0;
		lca=now;
		cout<<"LCA "<<lca<<" "<<b[lca]<<endl;
		if(b[lca]<=n)return 0;
	}
	return 1;
}
void solve()
{
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	tarjan(1,0);
	for(int i=1;i<=n;i++)b[i]=n+1;
	for(int i=1;i<=k;i++)
		cin>>a[i],b[i]=i;
	for(int i=1;i<=n;i++)
	{
		cout<<"dfn "<<i<<" "<<dfn[i]<<endl;
	}
	// int l=0,r=k,ans=r;
	// while(l<r-1)
	// {
	// 	int mid=(l+r)>>1;
	// 	if(check(mid))ans=mid,r=mid;
	// 	else l=mid;
	// }
	// while(ans>0&&check(ans-1))ans--;
	// cout<<ans<<endl;
	cout<<"check"<<endl;
	cout<<check(1)<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}