#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
struct node{
	int x,y;
}p[maxn];
vector<int>v[maxn];
vector<int>bcc[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
stack<int>s;
int in[maxn];
ll c[maxn];
int n;
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	for(auto y:v[x])
	{
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		++tot;
		int y;
		do{
			y=s.top();s.pop();
			vis[y]=0;col[y]=tot;
			bcc[tot].push_back(y);
		}while(x!=y);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x;
		int to;cin>>to;
		cin>>p[i].y;
		if(to)v[to].push_back(i);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int x=1;x<=n;x++)
		for(auto y:v[x])
			if(col[x]!=col[y])
				in[col[y]]++;
	ll ans=0;
	for(int i=1;i<=tot;i++)
	{
		ll sum=0,mi=1e18;
		for(auto x:bcc[i])
		{
			sum+=p[x].y;
			mi=min(mi,1ll*p[x].y-p[x].x);
		}
		if(in[i]==0)c[i]=sum-mi;
		else c[i]=sum;
		ans+=c[i];
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