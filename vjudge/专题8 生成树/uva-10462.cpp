#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF64=1e18+7;
const int INF=1e9+7;
const int maxn=1e3+10;

class Tr{
public:
	struct Edge{int to,next,w;}edge[maxn];
	int head[maxn],cnt;
	int maxx[maxn][22];
	int f[maxn][22];
	int dep[maxn];
	void add(int from,int to,int w){
		edge[++cnt].w=w;
		edge[cnt].to=to;
		edge[cnt].next=head[from];
		head[from]=cnt;
	}
	void Add(int x,int y,int w){
		add(x,y,w);
		add(y,x,w);
	}
	void dfs(int x,int fa)
	{
		dep[x]=dep[fa]+1;
		f[x][0]=fa;
		for(int i=1;(1<<i)<=dep[x];i++)
		{
			f[x][i]=f[f[x][i-1]][i-1];
			maxx[x][i]=max(maxx[x][i-1],maxx[f[x][i-1]][i-1]);
		}
		for(int i=head[x];i;i=edge[i].next)
			if(edge[i].to!=fa){
				maxx[edge[i].to][0]=edge[i].w;
				dfs(edge[i].to,x);
			}
	}
	int lca(int x,int y){
		if(dep[x]<dep[y])swap(x,y);
		for (int j = 0, D = dep[x] - dep[y]; D; ++j, D >>= 1)
			if (D & 1) x = f[x][j];
		if(x==y)return x;
		for (int j = 8; ~j; --j)
			if (f[x][j] != f[y][j])
				x = f[x][j], y = f[y][j];
		return f[x][0];
	}
	int query(int x,int y)
	{
		int res=-INF;
		for(int i=8;i>=0;i--){
			if(dep[f[x][i]]>=dep[y]){
				res=max(res,maxx[x][i]);
				x=f[x][i];
			}
		}
		return res;
	}
}tr;




class DSU{
public:
	vector<int>f,num;
	DSU(){
		f.reserve(maxn);
	}
	void init(int n){
		f.resize(n+1);
		iota(f.begin(),f.end(),0);
	}
	int find(int r){
		return f[r]=f[r]==r?f[r]:find(f[r]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void merge(int x,int y){
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
			f[fa]=fb;
	}
}dsu;


class Kru{
public:
	struct node{int x,y,w,fl;};
	// vector<node>p;
	node p[maxn];
	int n,m;
	ll ans;
	Kru(){}
	void init(int _n){
		n=_n;ans=0;
		m=0;
		// p.clear();
		// p.resize(m+1);
		dsu.init(n);
	}
	void add(int x,int y,int w){
		p[++m]={x,y,w};
	}
	int run(){
		// sort(p.begin()+1,p.end(),[&](node a,node b){return a.w<b.w;});
		sort(p+1,p+1+m,[&](node a,node b){return a.w<b.w;});
		int num=n;
		for(int i=1;i<=m;i++)
		{
			auto &[x,y,w,fl]=p[i];
			if(!dsu.same(x,y)){
				num--;
				dsu.merge(x,y);
				tr.Add(x,y,w);
				ans+=w;
				fl=1;
			}
			if(num==1)break;
		}
		if(num!=1)ans=-1;
		return ans;
	}
	ll query()
	{
		tr.dfs(1,0);
		ll res=INF64;
		for(int i=1;i<=m;i++)
		{
			if(p[i].fl)continue;
			auto [x,y,w,fl]=p[i];
			int _lca=tr.lca(x,y);
			int tmpa=tr.query(x,_lca);
			int tmpb=tr.query(y,_lca);
			if(max(tmpa,tmpb)>-INF)
				res=min(res,ans-max(tmpa,tmpb)+w);
		}
		return (res==INF64?-1:res);
	}
}_k;


void solve(){
	int n,m;
	cin>>n>>m;
	_k.init(n);
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		_k.add(x,y,w);
	}
	ll ans_1 = _k.run();
	ll ans_2 = _k.query();
	if(ans_1==-1)cout<<"No way\n";
	else if(ans_2==-1)cout<<"No second way\n";
	else cout<<ans_2<<"\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case #"<<i<<" : ";
		solve();
	}
	return 0;
}
/*
	Suprit_young
4
5 4
1 2 5
3 2 5
4 2 5
5 4 5
5 3
1 2 5
3 2 5
5 4 5
5 5
1 2 5
3 2 5
4 2 5
5 4 5
4 5 6
1 0
*/