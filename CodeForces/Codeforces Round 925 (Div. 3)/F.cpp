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
bitset<maxn>vis;
stack<int>s;
int tot=0;
int n,k;
void init()
{
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
		dfn[i]=low[i]=vis[i]=0;
	}
	tot=indx=0;
}
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
	cin>>n>>k;
	init();
	for(int j=1;j<=k;j++)
	{
		int pre=0,x;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			if(i>2)v[x].push_back(pre);
			pre=x;
		}
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	cout<<((tot==n)?"YES\n":"NO\n");
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
1 4 4 1 3 5 5 3
 1 0 -1 1 1 0 -1
*/