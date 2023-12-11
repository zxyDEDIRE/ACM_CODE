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
struct Edge{int to,next;};
vector<Edge>edge;
vector<int>head;
int cnt=1;
vector<vector<int>>bcc;
vector<int>v[maxn];
vector<int>dfn,low,col,num,siz;
bitset<maxn>cut;
ll ans[maxn];
stack<int>s;
int bcc_cnt,indx,tot;
int n,m;
ll TOT;
void add(int from,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void tarjan(int x,int fa=0)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	int _cnt=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			_cnt++;
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				bcc_cnt++;
				bcc.push_back(vector<int>(1,x));
				cut[x]=1;
				int v;
				do{
					v=s.top();s.pop();
					bcc.back().push_back(v);
				}while(v!=y);
			}
		}
		else if(dfn[y]<dfn[x]&&i!=(fa^1))
			low[x]=min(low[x],dfn[y]);
	}
	if(fa==0&&_cnt==1)cut[x]=0;
}
void dfs(int x,int fa=0)
{
	siz[x]=num[x];
	for(auto y:v[x])
		if(y!=fa){
			dfs(y,x);
			siz[x]+=siz[y];
		}
}
ll f(int x)
{
	return 1ll*(x)*(x-1);
}
void _dfs(int x,int fa=0)
{
	ans[x]=f(num[x])+f(n-siz[x]);
	for(auto y:v[x])
	{
		if(y==fa)continue; 
		_dfs(y,x);
		ans[x]+=f(siz[y]);
	}
	// cout<<"x "<<x<<" siz:"<<siz[x]<<" num:"<<num[x]<<" ans:"<<ans[x]<<" "<<f(n-siz[x])<<endl;
}
void init()
{
	dfn.resize(n+3);
	low.resize(n+3);
	col.resize(n+3);
	num.resize(n+3);
	siz.resize(n+3);
	edge.resize(m*2+3);
	head.resize(n+3);
}
void solve()
{
	cin>>n>>m;
	init();
	TOT=1ll*(1+n-1)*(n-1)/2;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=0;i<bcc.size();i++){
		tot++;
		for(auto x:bcc[i]){
			if(!cut[x])
				col[x]=tot,num[tot]++;
		}
	}
	bcc.clear();
	for(int i=1;i<=n;i++)
		if(cut[i])
			col[i]=++tot,num[tot]++;
	for(int x=1;x<=n;x++)
	{
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(col[x]!=col[y])
				v[col[x]].push_back(col[y]);
		}
		head[x]=0;
	}
	for(int i=1;i<=tot;i++){
		sort(v[i].begin(),v[i].end());
		v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
	}

	// for(int i=1;i<=n;i++)
	// 	cout<<"col "<<i<<" "<<col[i]<<endl;
	// cout<<endl;

	dfs(1);
	_dfs(1);

	// cout<<endl;
	for(int i=1;i<=n;i++)
		if(cut[i])cout<<f(n)-ans[col[i]]<<endl;
		else cout<<(n-1)*2<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
5 7
1 2
2 3
1 3
3 4
4 5
3 5
2 4
*/