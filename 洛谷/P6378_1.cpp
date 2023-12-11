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
const int maxn=3e6+100;
namespace TA{
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
};


int id[maxn][21];
int w[maxn];
pii a[maxn];
int n,m,k,cnt,tot;
void add(int x,int y){
	// cout<<""<<x<<" "<<y<<endl;
	TA::v[x].push_back(y);
}
int find(int x,int y){
    if(id[x][y])return id[x][y];
    id[x][y]=++tot;
    if(!y){
    	add(id[x][y],x);
    }
    else {
    	add(id[x][y],find(x,y-1));
    	add(id[x][y],find(x+(1<<(y-1)),y-1));
    }
    return id[x][y];
}
void Add(int s,int x,int y)
{
	for(int i=20;i>=0;i--)
		if((y-x)>=(1<<i))
		{
			add(s,find(x,i));
			x+=(1<<i);
		}
}
void solve()
{
	cin>>n>>m>>k;
	tot=n*2;
	cnt=0;
	for(int i=1;i<=m;i++)
		cin>>a[i].first>>a[i].second;
	for(int i=1;i<=k;i++)
	{
		int num;
		cin>>num;
		vector<int>p;
		for(int j=0,x;j<num;j++){
			cin>>x;
			p.push_back(x);
			w[x]=++cnt;
		}
		int s=w[p[0]];
		int t=w[p.back()];
		for(int j=s;j<=t;j++)
		{
			if(j!=s)Add(j+n,s,j-1);
			if(j!=t)Add(j+n,j+1,t);
		}
	}
	// cout<<endl;
	for(int i=1;i<=m;i++)
	{
		auto [x,y]=a[i];
		x=w[x];y=w[y];
		add(x,y+n);
		add(y,x+n);
	}
	for(int i=1;i<=tot;i++)
		if(!TA::dfn[i])
			TA::tarjan(i);
	for(int i=1;i<=n;i++)
		if(TA::col[i]==TA::col[i+n]){
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