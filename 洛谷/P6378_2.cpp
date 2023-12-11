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
const int maxn=6e6+100;
vector<int>v[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
stack<int>s;
void tarjan(int x){
	dfn[x]=low[x]=++indx; vis[x]=1; s.push(x);
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(!dfn[y]){ tarjan(y); low[x]=min(low[x],low[y]); }
		else if(vis[y]) low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]){ ++tot;int y; do{ y=s.top();s.pop();vis[y]=0;col[y]=tot; }while(x!=y);
	}
}
vector<int>p;
int n,m,k;
void f()
{
	int t=p.size();
	for(int i=0;i<t;i++)
	{
		int x=p[i];
		v[x].push_back(x+n*2);
		v[x+n*3].push_back(x+n);
		if(i<t-1)
		{
			int y=p[i+1];
			v[x+n*2].push_back(y+n*2);
			v[y+n*3].push_back(x+n*3);
			v[x+n*2].push_back(y+n);
			v[y].push_back(x+n*3);
		}
	}
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		v[x+n].push_back(y);
		v[y+n].push_back(x);
	}
	for(int i=1;i<=k;i++)
	{
		int t;
		cin>>t;
		p.clear();
		for(int j=0,x;j<t;j++){
			cin>>x;p.push_back(x);
		}
		if(t==1)
		{
			v[p[0]+n].push_back(p[0]);
		}
		else
			f();
	}
	for(int i=1;i<=n*4;i++)
		if(!dfn[i])
			tarjan(i); 
	for(int i=1;i<=n;i++)
		if(col[i]==col[i+n]){
			cout<<"NIE\n";
			return ;
		}
	cout<<"TAK\n";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
4 2 1
1 2
3 4
4 1 2 3 4



*/