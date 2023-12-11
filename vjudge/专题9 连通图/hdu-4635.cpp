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
vector<int>v[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],num[maxn],tot;
bitset<maxn>vis;
stack<int>s;
int out[maxn];
int in[maxn];
int n,m;
void init(){
	for(int i=1;i<=n;i++){
		dfn[i]=low[i]=in[i]=out[i]=vis[i]=num[i]=0;
		v[i].clear();
	}
	indx=tot=0;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	for(auto y:v[x])
	{
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]){
		++tot;
		int y;
		do{
			y=s.top();s.pop();
			vis[y]=0;col[y]=tot;
			num[tot]++;
		}while(x!=y);
	}
}
void solve()
{
	cin>>n>>m;
	if(n==1){
		cout<<0<<endl;
		return ;
	}
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++) 
		if(!dfn[i])
			tarjan(i);
	if(tot==1){
		cout<<-1<<endl;
		return ;
	}
	for(int x=1;x<=n;x++)
		for(auto y:v[x])
			if(col[x]!=col[y])
				out[col[x]]++,in[col[y]]++;
	ll ans=0,T=1ll*n*(n-1);
	for(int i=1;i<=tot;i++)
	{
		if(out[i]&&in[i])continue;
		ll x=num[i],y=n-x;
		ans=max(ans,T-x*y-m);
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case "<<i<<": ";
		solve();
	}
	return 0;
}
/*
*/