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
vector<int>e[maxn];
pp(4) p[maxn];
int low[maxn],dfn[maxn],indx;
int col[maxn],in[maxn],tot;
bitset<maxn>vis;
stack<int>s;
int n,m;
void init()
{
	for(int i=1;i<=n;i++)
	{
		dfn[i]=low[i]=vis[i]=in[i]=0;
		v[i].clear();
		e[i].clear();
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
		++tot;
		int y;
		do{
			y=s.top();s.pop();
			vis[y]=0;
			col[y]=tot;
		}while(x!=y);
	}
}
void dfs(int x,vector<int>& list)
{
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		int d=e[x][i];
		list.push_back(d);
		if(!vis[y])
			dfs(y,list);
	}
}
void solve()
{
	cin>>n>>m;
	init();
	vector<int>one,two;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<4;j++)
			cin>>p[i][j];
		if(p[i][1]==2&&p[i][3]==2)
			two.push_back(i);
		else if(p[i][1]==1&&p[i][3]==1)
			one.push_back(i);
		else if(p[i][1]==1&&p[i][3]==2)
		{
			v[p[i][0]].push_back(p[i][2]);
			e[p[i][0]].push_back(i);
		}
		else if(p[i][1]==2&&p[i][3]==1)
		{
			v[p[i][2]].push_back(p[i][0]);
			e[p[i][2]].push_back(i);
		}
	}

	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);

	for(int x=1;x<=n;x++)
		for(auto y:v[x])
			if(col[x]!=col[y])
				in[col[y]]++;

	vector<int>list,ans;

	for(auto x:one)
		ans.push_back(x);
	vis.reset();
	for(auto i:two){
		int x=p[i][0];
		if(in[col[x]]==0&&!vis[x])
			dfs(x,list);
		x=p[i][2];
		if(in[col[x]]==0&&!vis[x])
			dfs(x,list);
	}

	for(int i=1;i<=n;i++)
		if(in[col[i]]==0&&!vis[i])
			dfs(i,list);

	reverse(list.begin(),list.end());
	ans.insert(ans.end(),list.begin(),list.end());
	for(auto x:two)
		ans.push_back(x);


	map<int,int>mp;
	for(auto x:ans)
	{
		mp[p[x][0]]=p[x][1];
		mp[p[x][2]]=p[x][3];
	}
	int sum=0;
	for(auto [x,y]:mp)
		sum+=y;
	cout<<sum<<endl;
	for(auto x:ans)
		cout<<x<<" ";cout<<endl;
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