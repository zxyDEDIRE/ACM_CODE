/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=2e6;
vector<int>v[maxn];
vector<int>G[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],num[maxn],tot;
bitset<maxn>vis;
int dp[maxn];
int in[maxn];
int f[maxn];
stack<int>s;
int n,m,mod;
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
			col[y]=tot;
			num[tot]++;
		}while(x!=y);
	}
}
void solve()
{
	cin>>n>>m>>mod;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);

	for(int x=1;x<=n;x++)
		for(auto y:v[x])
			if(col[x]!=col[y])
				G[col[x]].push_back(col[y]),in[col[y]]++;

	queue<int>q;
	for(int i=1;i<=tot;i++)
		if(!in[i])
			q.push(i),f[i]=1;

	int ma=0,ans=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		dp[x]+=num[x];
		for(auto y:G[x])
		{
			in[y]--;
			if(dp[y]<dp[x])f[y]=0;
			dp[y]=max(dp[y],dp[x]);
			if(dp[y]==dp[x])
				f[y]+=f[x],f[y]%=mod;
			if(!in[y])
				q.push(y);
		}
		if(dp[x]>ma)
			ma=dp[x],ans=0;
		if(dp[x]==ma)
			ans+=f[x],ans%=mod;
	}
	cout<<ma<<endl;
	cout<<ans<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 4 1
1 2
2 1
1 3
2 3

7 8 100000
1 2 
1 3
2 4
3 4
4 5
4 6
5 7
6 7



*/