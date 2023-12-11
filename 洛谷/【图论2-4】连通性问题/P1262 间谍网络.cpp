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
vector<vector<int>>v,G;
vector<int>low,dfn,col,num,w,c,in;
vector<bool>vis;
stack<int>s;
int indx,tot;
int n,m,k;
void init()
{
	v.resize(n+1);
	G.resize(n+1);
	w.resize(n+1);
	c.resize(n+1);
	low.resize(n+1);
	dfn.resize(n+1);
	col.resize(n+1);
	vis.resize(n+1);
	in.resize(n+1);
	for(int i=1;i<=n;i++)
		c[i]=w[i]=INF;
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
			y=s.top();
			s.pop();
			col[y]=tot;
			vis[y]=0;
			c[tot]=min(c[tot],w[y]);
		}while(y!=x);
	}
}
void solve()
{
	cin>>n>>k;
	init();
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		w[x]=y;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	// cout<<"SDF"<<endl;
	for(int x=1;x<=n;x++)
		for(auto y:v[x])
			if(col[x]!=col[y])
				G[col[x]].push_back(col[y]),in[col[y]]++;
	for(int i=1;i<=n;i++)
		if(in[col[i]]==0&&c[col[i]]==INF){
			cout<<"NO"<<endl;
			cout<<i<<endl;
			return ;
		}
	int ans=0;
	for(int i=1;i<=tot;i++)
		if(in[i]==0){
			ans+=c[i];
		}
	cout<<"YES"<<endl;
	cout<<ans<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}