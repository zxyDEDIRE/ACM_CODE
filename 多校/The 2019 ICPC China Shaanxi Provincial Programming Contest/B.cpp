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
vector<int>v[maxn];
vector<int>G[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],tot,in[maxn],num[maxn];
bitset<maxn>vis;
stack<int>s;
char mp[maxn];
int n,m;
int get(int x,int y)
{
	return m*(x-1)+y;
}
void init()
{
	vis.reset();
	for(int i=1;i<=n*m;i++)
	{
		in[i]=num[i]=0;
		v[i].clear();
		G[i].clear();
		dfn[i]=low[i]=0;
	}
	tot=0;
	indx=0;
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
			col[y]=tot;
			num[tot]++;
		}while(x!=y);
	}
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[get(i,j)];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int now;
			cin>>now;
			int x=i,y=j,flag=1;
			if(mp[get(i,j)]=='u')
			{
				x=i-now;
				if(x<1)flag=0;
			}
			else if(mp[get(i,j)]=='d')
			{
				x=i+now;
				if(x>n)flag=0;
			}
			else if(mp[get(i,j)]=='l')
			{
				y=j-now;
				if(y<1)flag=0;
			}
			else if(mp[get(i,j)]=='r')
			{
				y=j+now;
				if(y>m)flag=0;
			}
			if(!flag)continue;
			int a=get(i,j);
			int b=get(x,y);
			v[a].push_back(b);
		}
	for(int i=1;i<=n*m;i++)
		if(!dfn[i])
			tarjan(i);
	for(int x=1;x<=n*m;x++)
		for(auto y:v[x])
			if(col[x]!=col[y])
				G[col[y]].push_back(col[x]);
	for(int i=1;i<=tot;i++)
	{
		sort(G[i].begin(),G[i].end());
		G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());
		for(auto x:G[i]){
			in[x]++;
		}
	}
	queue<int>q;
	for(int i=1;i<=tot;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto y:G[x])
		{
			num[y]+=num[x];
			in[y]--;
			if(!in[y])
				q.push(y);
		}
	}
	for(int i=1;i<=tot;i++)
		if(num[i]==n*m){
			cout<<"Yes"<<endl;
			return ;
		}
	cout<<"No"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
2 3
rdd
url
2 1 1
1 1 2

*/